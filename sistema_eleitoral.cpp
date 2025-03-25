#include "sistema_eleitoral.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <locale>

string iso_8859_1_to_utf8(string &str)
{
  // adaptado de: https://stackoverflow.com/a/39884120 :-)
  string strOut;
  for (string::iterator it = str.begin(); it != str.end(); ++it)
  {
    uint8_t ch = *it;
    if (ch < 0x80)
    {
      // já está na faixa ASCII (bit mais significativo 0), só copiar para a saída
      strOut.push_back(ch);
    }
    else
    {
      // está na faixa ASCII-estendido, escrever 2 bytes de acordo com UTF-8
      // o primeiro byte codifica os 2 bits mais significativos do byte original (ISO-8859-1)
      strOut.push_back(0b11000000 | (ch >> 6));
      // o segundo byte codifica os 6 bits menos significativos do byte original (ISO-8859-1)
      strOut.push_back(0b10000000 | (ch & 0b00111111));
    }
  }
  return strOut;
}

sistema_eleitoral::sistema_eleitoral(int cidade, string path_candidatos, string path_votos, calendario data_eleicao) {

    ifstream arquivo_candidatos, arquivo_votos;
    istringstream linha_atual;

    arquivo_candidatos.open(path_candidatos);
    string linha;
    getline(arquivo_candidatos, linha);
    getline(arquivo_candidatos, linha);
    linha_atual = istringstream(linha);

    while(!linha.empty()) {

        string dado_lido;
        for(int i = 0; i < 11; i++) getline(linha_atual, dado_lido, ';');
        getline(linha_atual, dado_lido, ';');

        int flag_vereador = 1, flag_cidade = 1;

        dado_lido.erase(remove(dado_lido.begin(), dado_lido.end(), '\"'), dado_lido.end());

        // Seta a flag_cidade para 0 caso a cidade lida não seja a do código do município informado
        if(stoi(dado_lido) != cidade) flag_cidade = 0;


        getline(linha_atual, dado_lido, ';');
        getline(linha_atual, dado_lido, ';');

        dado_lido.erase(remove(dado_lido.begin(), dado_lido.end(), '\"'), dado_lido.end());

        // Seta a flag_vereador para 0 caso o candidato lido não esteja concorrendo ao cargo de vereador
        if(stoi(dado_lido) != 13) flag_vereador = 0;

        int numero;
        genero mfo;

        int numero_partido;
        bool federacao = false;

        for(int i = 0; i < 3; i++) getline(linha_atual, dado_lido, ';');

        dado_lido.erase(remove(dado_lido.begin(), dado_lido.end(), '\"'), dado_lido.end());
        numero = stoi(dado_lido);

        getline(linha_atual, dado_lido, ';');
        getline(linha_atual, dado_lido, ';');

        dado_lido.erase(remove(dado_lido.begin(), dado_lido.end(), '\"'), dado_lido.end());
        string nome(dado_lido);
        nome = iso_8859_1_to_utf8(nome);

        for(int i = 0; i < 6; i++) getline(linha_atual, dado_lido, ';');

        dado_lido.erase(remove(dado_lido.begin(), dado_lido.end(), '\"'), dado_lido.end());
        dado_lido = iso_8859_1_to_utf8(dado_lido);
        if(!dado_lido.compare("FEDERAÇÃO")) federacao = true;

        getline(linha_atual, dado_lido, ';');
        dado_lido.erase(remove(dado_lido.begin(), dado_lido.end(), '\"'), dado_lido.end());
        numero_partido = stoi(dado_lido);
        getline(linha_atual, dado_lido, ';');
        dado_lido.erase(remove(dado_lido.begin(), dado_lido.end(), '\"'), dado_lido.end());
        string nome_partido(dado_lido);
        nome_partido = iso_8859_1_to_utf8(dado_lido);

        partidos.insert({numero_partido, partido(numero_partido, nome_partido, federacao)});

        // As flags só são verificadas aqui porque precisamos adicionar um partido mesmo caso nenhum vereador tenha concorrido nele,
        // mas algum prefeito sim
        if(flag_vereador == 0 || flag_cidade == 0) {
            getline(arquivo_candidatos, linha);
            linha_atual = istringstream(linha);
            continue;
        }

        for(int i = 0; i < 10; i++) getline(linha_atual, dado_lido, ';');

        dado_lido.erase(remove(dado_lido.begin(), dado_lido.end(), '\"'), dado_lido.end());
        istringstream data(dado_lido);
        string dia;
        string mes;
        string ano;
        getline(data, dia, '/');
        getline(data, mes, '/');
        getline(data, ano, '/');
        calendario nascimento(stoi(dia), stoi(mes), stoi(ano));
        getline(linha_atual, dado_lido, ';');
        getline(linha_atual, dado_lido, ';');
        dado_lido.erase(remove(dado_lido.begin(), dado_lido.end(), '\"'), dado_lido.end());
        if(stoi(dado_lido) == 2) mfo = MASCULINO;
        else if(stoi(dado_lido) == 4) mfo = FEMININO;
        else mfo = OUTROS;

        for(int i = 0; i < 10; i++) getline(linha_atual, dado_lido, ';');

        bool eleito;
        dado_lido.erase(remove(dado_lido.begin(), dado_lido.end(), '\"'), dado_lido.end());
        if(stoi(dado_lido) > 0 && stoi(dado_lido) < 4) eleito = true;
        else eleito = false;

        // Vereadores com candidatura inválida não são adicionados à hash de candidatos
        if(stoi(dado_lido) > -1) {
            candidatos.insert({numero, candidato(numero, nome, &partidos.at(numero_partido), nascimento, eleito, mfo)});
            partidos.at(numero_partido).adiciona_candidato(&candidatos.at(numero));
        }

        getline(arquivo_candidatos, linha);
        linha_atual = istringstream(linha);
        
    }

    arquivo_votos.open(path_votos);
    getline(arquivo_votos, linha);
    getline(arquivo_votos, linha);
    linha_atual = istringstream(linha);

    while(!linha.empty()) {

        string dado_lido;
        for(int i = 0; i < 13; i++) getline(linha_atual, dado_lido, ';');
        getline(linha_atual, dado_lido, ';');

        dado_lido.erase(remove(dado_lido.begin(), dado_lido.end(), '\"'), dado_lido.end());

        // Se não for um voto na cidade que queremos, simplesmente ignora e passa para a próxima linha
        if(stoi(dado_lido) != cidade) {
            getline(arquivo_votos, linha);
            linha_atual = istringstream(linha);
            continue;
        }

        for(int i = 0; i < 4; i++) getline(linha_atual, dado_lido, ';');

        dado_lido.erase(remove(dado_lido.begin(), dado_lido.end(), '\"'), dado_lido.end());
        // Verifica se é voto de vereador
        if(stoi(dado_lido) != 13) {
            getline(arquivo_votos, linha);
            linha_atual = istringstream(linha);
            continue;
        }

        int numero_candidato;
        int votos = 0;

        getline(linha_atual, dado_lido, ';');
        
        getline(linha_atual, dado_lido, ';');
        dado_lido.erase(remove(dado_lido.begin(), dado_lido.end(), '\"'), dado_lido.end());
        numero_candidato = stoi(dado_lido);

        getline(linha_atual, dado_lido, ';');

        getline(linha_atual, dado_lido, ';');
        dado_lido.erase(remove(dado_lido.begin(), dado_lido.end(), '\"'), dado_lido.end());
        votos = stoi(dado_lido);

        // Filtra votos de legenda e ignora votos brancos ou nulos
        if(numero_candidato <= 94) {
            partidos.at(numero_candidato).adiciona_votos_legenda(votos);
            getline(arquivo_votos, linha);
            linha_atual = istringstream(linha);
            continue;
        }

        if(candidatos.find(numero_candidato) != candidatos.end()) candidatos.at(numero_candidato).aumenta_votos(votos);

        getline(arquivo_votos, linha);
        linha_atual = istringstream(linha); 
    }

    arquivo_votos.close();
    arquivo_candidatos.close();

}

const map<int, candidato> &sistema_eleitoral::get_candidatos() const {
   return this->candidatos;
}

const map<int, partido> &sistema_eleitoral::get_partidos() const {
    return this->partidos;
}
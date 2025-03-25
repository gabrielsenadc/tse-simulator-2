#include "sistema_eleitoral.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

sistema_eleitoral::sistema_eleitoral(int cidade, string path_candidatos, string path_votos, calendario data_eleicao) {

    ifstream arquivo_candidatos, arquivo_votos;
    istringstream linha_atual;

    arquivo_candidatos.open(path_candidatos);
    string linha;
    getline(arquivo_candidatos, linha);
    linha_atual = istringstream(linha);

    while(!linha.empty()) {

        string dado_lido;
        getline(linha_atual, dado_lido, ';');
        for(int i = 0; i < 11; i++) getline(linha_atual, dado_lido, ';');

        int flag_vereador = 1, flag_cidade = 1;

        // Seta a flag_cidade para 0 caso a cidade lida não seja a do código do município informado
        if(stoi(dado_lido) != cidade) flag_cidade = 0;

        getline(linha_atual, dado_lido, ';');
        getline(linha_atual, dado_lido, ';');

        // Seta a flag_vereador para 0 caso o candidato lido não esteja concorrendo ao cargo de vereador
        if(stoi(dado_lido) != 13) flag_vereador = 0;

        int numero;
        genero mfo;
        //candidato?

        int numero_partido;
        bool federacao = false;

        for(int i = 0; i < 3; i++) getline(linha_atual, dado_lido, ';');

        numero = stoi(dado_lido);

        getline(linha_atual, dado_lido, ';');
        getline(linha_atual, dado_lido, ';');

        string nome(dado_lido);

        for(int i = 0; i < 6; i++) getline(linha_atual, dado_lido, ';');

        if(!dado_lido.compare("FEDERAÇÃO")) federacao = true;

        getline(linha_atual, dado_lido, ';');
        numero_partido = stoi(dado_lido);
        getline(linha_atual, dado_lido, ';');
        string nome_partido(dado_lido);

        partidos.insert({numero_partido, partido(numero_partido, nome_partido, federacao)});

        // As flags só são verificadas aqui porque precisamos adicionar um partido mesmo caso nenhum vereador tenha concorrido nele,
        // mas algum prefeito sim
        if(flag_vereador == 0 || flag_cidade == 0) {
            getline(arquivo_candidatos, linha);
            linha_atual = istringstream(linha);
            continue;
        }

        for(int i = 0; i < 10; i++) getline(linha_atual, dado_lido, ';');

        // Pode haver erros em todo esse trecho envolvendo datas, gênero e a variável eleito !!!!!!!!!!!!!!!!!!!!!!!!!!!
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
        if(stoi(dado_lido) == 2) mfo = MASCULINO;
        else if(stoi(dado_lido) == 4) mfo = FEMININO;
        else mfo = OUTROS;


        for(int i = 0; i < 10; i++) getline(linha_atual, dado_lido, ';');

        bool eleito;
        if(stoi(dado_lido) > -1) eleito = true;
        else eleito = false;

        getline(linha_atual, dado_lido, ';');
        string eleicao(dado_lido);
        int resultado = 0;
        if(!eleicao.compare("ELEITO POR QP")) resultado = 1;
        else if(!eleicao.compare("ELEITO POR MÉDIA")) resultado = 2;

        // Vereadores com candidatura inválida não são adicionados à hash de candidatos
        if(eleito) {
            candidato c(numero, nome, &partidos.at(numero_partido), nascimento, eleito, mfo);
            candidatos.insert({c.get_numero(), c});
            partidos.at(numero_partido).adiciona_candidato(c);
        }

        getline(arquivo_candidatos, linha);
        linha_atual = istringstream(linha);
        
    }

    arquivo_votos.open(path_votos);
    getline(arquivo_votos, linha);
    linha_atual = istringstream(linha);

    // Copiar e adaptar a parte respectiva no T1

    arquivo_candidatos.close();
}

const map<int, candidato> &sistema_eleitoral::get_candidatos() const {
    map<int, candidato> copia(this -> candidatos);
    return copia;
}

const map<int, partido> &sistema_eleitoral::get_partidos() const {
    map<int, partido> copia(this -> partidos);
    return copia;
}
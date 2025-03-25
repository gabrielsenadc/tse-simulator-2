/**
 * 2o Trabalho de Programação Orientada a Objetos (2024/02)
 * Professor: João Paulo Andrade Almeida
 * Alunos: Eduardo Silva (2023100580) e Gabriel Sena (2023100257)
 */

#include <string>
#include <iostream>
#include <iostream>
#include <sstream>
#include "candidato.hpp"
#include "partido.hpp"
#include "relatorio.hpp"
#include "sistema_eleitoral.hpp"
#include "calendario.hpp"

using namespace std;

int main(int argc, char **argv){

    locale lbrasil("pt_BR.UTF-8");
    locale::global(lbrasil);

    cout.imbue(lbrasil);

    if(argc < 5) {
        cout << "Parametros Faltando" << endl;
        exit(1);
    }

    int cidade = stoi(argv[1]);

    istringstream data(argv[4]);
    string dia;
    string mes;
    string ano;
    getline(data, dia, '/');
    getline(data, mes, '/');
    getline(data, ano, '/');
    calendario data_eleicao(stoi(dia), stoi(mes), stoi(ano));

    sistema_eleitoral se(cidade, string(argv[2]), string(argv[3]), data_eleicao);

    relatorio r(se.get_candidatos(), se.get_partidos(), data_eleicao);
    r.gera_relatorio();

    cout.imbue(locale("C"));
    std::locale::global(std::locale("C"));

    return 0;
}
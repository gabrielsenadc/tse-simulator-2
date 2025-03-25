#include <string>
#include <iostream>

#include "candidato.hpp"
#include "partido.hpp"
#include "relatorio.hpp"
#include "sistema_eleitoral.hpp"
#include "calendario.hpp"

using namespace std;

int main(int argc, char **argv){
    if(argc < 5) {
        cout << "Parametros Faltando" << endl;
        exit(1);
    }

    int cidade = stoi(argv[1]);

    calendario data(6, 10, 2024);

    sistema_eleitoral se(cidade, string(argv[2]), string(argv[3]), data);

    relatorio r(se.get_candidatos(), se.get_partidos(), data);
    r.gera_relatorio();

    return 0;
}
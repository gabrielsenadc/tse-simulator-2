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
    int cidade = stoi(argv[0]);

    calendario data(8, 9, 2024);

    sistema_eleitoral se(cidade, string(argv[1]), string(argv[2]), data);

    relatorio r(se.get_candidatos(), se.get_partidos());
    r.gera_relatorio();

    return 0;
}
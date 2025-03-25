#include <string>
#include <iostream>

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

    calendario data(6, 10, 2024);

    sistema_eleitoral se(cidade, string(argv[2]), string(argv[3]), data);

    relatorio r(se.get_candidatos(), se.get_partidos(), data);
    r.gera_relatorio();

    locale loc(cout.getloc(), new numpunct<char>);
	cout.imbue(loc);

    cout.imbue(locale("C"));
    std::locale::global(std::locale("C"));

    return 0;
}
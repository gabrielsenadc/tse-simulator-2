#include "apurador.hpp"

apurador::apurador(int cidade, string path_candidatos, string path_votos, chrono::year_month_day data_eleicao) {

    // to do

}

const map<int, candidato> &apurador::get_candidatos() const {
    map<int, candidato> copia(this -> candidatos);
    return copia;
}

const map<int, partido> &apurador::get_partidos() const {
    map<int, partido> copia(this -> partidos);
    return copia;
}
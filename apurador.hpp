#ifndef apurador_h
#define apurador_h

#include <map>
#include <chrono>
#include "candidato.hpp"
#include "partido.hpp"

class apurador {

    map<int, candidato> candidatos;
    map<int, partido> partidos;

    public:

    apurador(int cidade, string path_candidatos, string path_votos, chrono::year_month_day data_eleicao);

    const map<int, candidato> &get_candidatos() const;

    const map<int, partido> &get_partidos() const;

};

#endif
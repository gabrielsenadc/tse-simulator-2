#ifndef apurador_h
#define apurador_h

#include <map>
#include "calendario.hpp"
#include "candidato.hpp"
#include "partido.hpp"

class sistema_eleitoral {

    map<int, candidato> candidatos;
    map<int, partido> partidos;

    public:

    sistema_eleitoral(int cidade, string path_candidatos, string path_votos, calendario data_eleicao);

    const map<int, candidato> &get_candidatos() const;

    const map<int, partido> &get_partidos() const;

};

#endif
/**
 * 2o Trabalho de Programação Orientada a Objetos (2024/02)
 * Professor: João Paulo Andrade Almeida
 * Alunos: Eduardo Silva (2023100580) e Gabriel Sena (2023100257)
 */

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
/**
 * 2o Trabalho de Programação Orientada a Objetos (2024/02)
 * Professor: João Paulo Andrade Almeida
 * Alunos: Eduardo Silva (2023100580) e Gabriel Sena (2023100257)
 */

#ifndef RELATORIO_HPP
#define RELATORIO_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include "partido.hpp"
#include "candidato.hpp"
#include "calendario.hpp"

using namespace std;

class relatorio {
    vector<candidato> candidatos;
    vector<candidato> eleitos;
    map<int, partido> partidos;
    calendario data_eleicao;

    public:

    relatorio(map<int, candidato> candidatos, map<int, partido> partidos, const calendario &data_eleicao);

    void relatorio1() const;
    void relatorio2() const;
    void relatorio3() const;
    void relatorio4() const;
    void relatorio5() const;
    void relatorio6() const;
    void relatorio7() const;
    void relatorio8() const;
    void relatorio9() const;
    void relatorio10() const;

    void gera_relatorio() const;

};

#endif
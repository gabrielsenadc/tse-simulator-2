#ifndef RELATORIO_HPP
#define RELATORIO_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include "partido.hpp"
#include "candidato.hpp"

using namespace std;

class relatorio {
    vector<candidato> candidatos;
    vector<candidato> eleitos;
    map<int, partido> partidos;

    public:

    relatorio(map<int, candidato> candidatos, map<int, partido> partidos);

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
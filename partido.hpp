#ifndef PARTIDO_HPP
#define PARTIDO_HPP

#include <iostream>
#include <string>
#include <map>

class partido;

#include "candidato.hpp"

using namespace std;

class partido {
    int numero;
    string nome;
    map<int, candidato> candidatos;
    int quantidade_eleitos;
    int votos_nominais;
    int votos_legenda;
    bool federacao;

    public:
    partido(const int &numero, const string &nome, const bool federacao) : numero(numero), nome(nome), federacao(federacao) {}

    const int &get_numero() const;

    const string &get_nome() const;

    const int &get_quantidade_eleitos() const;

    const int &get_votos_nominais() const;

    const int &get_votos_legenda() const;

    const int &get_votos_totais() const;

    const bool &is_federacao() const;

    void adiciona_candidato(candidato c);

    void adiciona_votos_nominais(int novos_votos);

    void adiciona_votos_legenda(int novos_votos);

    map<int, candidato> get_candidatos() const;

    void sort_candidatos();
    
};

bool compara_partidos(partido p1, partido p2);

bool compara_partidos_posicao(partido p1, partido p2);

#endif
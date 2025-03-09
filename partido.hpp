#ifndef PARTIDO_HPP
#define PARTIDO_HPP

#include <iostream>
#include <string>
#include <map>
#include "partido.hpp"
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
    //Comparator<Candidato> comp_candidatos = new ComparaCandidatos();

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

    // função de organizar candidatos faltando

    void imprime();
};

#endif
#ifndef CANDIDATO_HPP
#define CANDIDATO_HPP

#include <iostream>
#include <string>
#include <chrono>
#include "partido.hpp"

using namespace std;
using namespace std::chrono;

class candidato {
    int numero;
    string nome;
    partido p;
    chrono::year_month_day nascimento;
    int eleito;
    int genero;
    int votos;

    public:

    candidato(const int &numero, const string &nome, const partido &p, const chrono::year_month_day &nascimento, const int &eleito, const int genero) :
        numero(numero), nome(nome), p(p), nascimento(nascimento), eleito(eleito), genero(genero) {}

    const int &get_numero() const;

    const string &get_nome() const;

    const partido &get_partido() const;

    const chrono::year_month_day &get_nascimento() const;

    const int &get_eleito() const;

    const int &get_genero() const;

    const int &get_votos() const;

    const int &get_idade(chrono::year_month_day data) const;

    const bool &is_mais_velho(candidato x) const;

    void set_name(const string &name);

    void aumenta_votos(const int novos_votos);

    void imprime();
};

#endif
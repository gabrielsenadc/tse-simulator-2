/**
 * 2o Trabalho de Programação Orientada a Objetos (2024/02)
 * Professor: João Paulo Andrade Almeida
 * Alunos: Eduardo Silva (2023100580) e Gabriel Sena (2023100257)
 */

#ifndef CANDIDATO_HPP
#define CANDIDATO_HPP

#include <iostream>
#include <string>

class candidato;

#include "partido.hpp"
#include "calendario.hpp"

using namespace std;

enum genero {
    MASCULINO,
    FEMININO,
    OUTROS
};

class candidato {
    int numero;
    string nome;
    partido * p;
    calendario nascimento;
    int eleito;
    genero mfo;
    int votos = 0;

    public:

    candidato(const int &numero, const string &nome, partido * p, const calendario &nascimento, const bool &eleito, const genero mfo) :
        numero(numero), nome(nome), p(p), nascimento(nascimento), eleito(eleito), mfo(mfo) {}

    const int &get_numero() const;

    const string &get_nome() const;

    partido * get_partido() const;

    const calendario &get_nascimento() const;

    bool get_eleito() const;

    const genero &get_genero() const;

    const int &get_votos() const;

    int get_idade(calendario data) const;

    void aumenta_votos(const int novos_votos);

};

bool compara_candidatos(candidato c1, candidato c2);

bool compara_candidatos_ponteiro(candidato * c1, candidato * c2);

#endif
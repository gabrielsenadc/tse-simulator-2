/**
 * 2o Trabalho de Programação Orientada a Objetos (2024/02)
 * Professor: João Paulo Andrade Almeida
 * Alunos: Eduardo Silva (2023100580) e Gabriel Sena (2023100257)
 */

#include "candidato.hpp"

const int &candidato::get_numero() const {
    return this -> numero;
}

const string &candidato::get_nome() const {
    return this -> nome;
}

partido * candidato::get_partido() const {
    return this -> p;
}

const calendario &candidato::get_nascimento() const {
    return this -> nascimento;
}

bool candidato::get_eleito() const {
    return this -> eleito;
}

const genero &candidato::get_genero() const {
    return this -> mfo;
}

const int &candidato::get_votos() const {
    return this -> votos;
}

int candidato::get_idade(calendario data) const {
    return calendario_diferenca_anos(this -> nascimento, data);
}

void candidato::aumenta_votos(const int novos_votos) {
    this -> votos += novos_votos;
    this->p->adiciona_votos_nominais(novos_votos);
}

bool compara_candidatos(candidato c1, candidato c2){
    if(c1.get_votos() != c2.get_votos()) return c1.get_votos() > c2.get_votos();

    if(calendario_mais_antigo(c1.get_nascimento(), c2.get_nascimento()) == 1) return true;
    else return false;
}

bool compara_candidatos_ponteiro(candidato * c1, candidato * c2){
    if(c1->get_votos() != c2->get_votos()) return c1->get_votos() > c2->get_votos();

    if(calendario_mais_antigo(c1->get_nascimento(), c2->get_nascimento()) == 1) return true;
    else return false;
}

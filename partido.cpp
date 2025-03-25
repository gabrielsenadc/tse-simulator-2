/**
 * 2o Trabalho de Programação Orientada a Objetos (2024/02)
 * Professor: João Paulo Andrade Almeida
 * Alunos: Eduardo Silva (2023100580) e Gabriel Sena (2023100257)
 */

#include "partido.hpp"

const int &partido::get_numero() const {
    return this -> numero;
}

const string &partido::get_nome() const {
    return this -> nome;
}

const int &partido::get_quantidade_eleitos() const {
    return this -> quantidade_eleitos;
}

const int &partido::get_votos_nominais() const {
    return this -> votos_nominais;
}

const int &partido::get_votos_legenda() const {
    return this -> votos_legenda;
}

int partido::get_votos_totais() const {
    return this -> get_votos_nominais() + this -> get_votos_legenda();
}

const bool &partido::is_federacao() const {
    return this -> federacao;
}

void partido::adiciona_candidato(candidato * c) {
    this -> candidatos.push_back(c);
    if(c->get_eleito()) this -> quantidade_eleitos++;
}

void partido::adiciona_votos_nominais(int novos_votos) {
    this -> votos_nominais += novos_votos;
}

void partido::adiciona_votos_legenda(int novos_votos) {
    this -> votos_legenda += novos_votos;
}

vector<candidato*> partido::get_candidatos() const{
    return this->candidatos;
}

void partido::sort_candidatos() {
    sort(this->candidatos.begin(), this->candidatos.end(), compara_candidatos_ponteiro);
}

candidato * partido::get_candidato_posicao(int pos){
    return this->candidatos[pos];
}

bool compara_partidos(partido p1, partido p2) {
    if(p2.get_votos_totais() == p1.get_votos_totais()) return p2.get_numero() > p1.get_numero();
    return p2.get_votos_totais() < p1.get_votos_totais();
}

bool compara_partidos_posicao(partido p1, partido p2) {
    candidato * c1 = p1.get_candidato_posicao(0);
    candidato * c2 = p2.get_candidato_posicao(0);

    return compara_candidatos_ponteiro(c1, c2);
}
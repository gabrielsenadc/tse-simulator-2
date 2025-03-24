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

const int &partido::get_votos_totais() const {
    return this -> get_votos_nominais() + this -> get_votos_legenda();
}

const bool &partido::is_federacao() const {
    return this -> federacao;
}

void partido::adiciona_candidato(candidato c) {
    this -> candidatos.insert({c.get_numero(), c});
}

void partido::adiciona_votos_nominais(int novos_votos) {
    this -> votos_nominais += novos_votos;
}

void partido::adiciona_votos_legenda(int novos_votos) {
    this -> votos_legenda += novos_votos;
}

map<int, candidato> partido::get_candidatos() const{
    return this->candidatos;
}

void partido::sort_candidatos() {
    sort(this->candidatos.begin(), this->candidatos.end(), compara_candidatos);
}

bool compara_partidos(partido p1, partido p2) {
    if(p1.get_votos_totais() != p2.get_votos_totais()) return p1.get_votos_totais() > p2.get_votos_totais();

    return p2.get_numero() > p1.get_numero();
}

// Essa aqui não está pronta
bool compara_partidos_posicao(partido p1, partido p2) {
    return true;
}
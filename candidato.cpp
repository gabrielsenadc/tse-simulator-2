#include "candidato.hpp"

const int &candidato::get_numero() const {
    return this -> numero;
}

const string &candidato::get_nome() const {
    return this -> nome;
}

const partido &candidato::get_partido() const {
    return this -> p;
}

const chrono::year_month_day &candidato::get_nascimento() const {
    return this -> nascimento;
}

const int &candidato::get_eleito() const {
    return this -> eleito;
}

const int &candidato::get_genero() const {
    return this -> genero;
}

const int &candidato::get_votos() const {
    return this -> votos;
}

const int &candidato::get_idade(chrono::year_month_day data) const {
    
    sys_days nascimento = sys_days(this -> nascimento);
    sys_days atual = sys_days(data);

    auto diferenca = duration_cast<years>(atual - nascimento);

    return diferenca.count();
}

const bool &candidato::is_mais_velho(candidato x) const {
    return sys_days(this -> nascimento) > sys_days(x.get_nascimento());
}

void candidato::aumenta_votos(const int novos_votos) {
    this -> votos += novos_votos;
}

void imprime(); // to do
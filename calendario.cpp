#include "calendario.hpp"

const int &calendario::get_dia() const {
    return this -> dia;
}

const int &calendario::get_mes() const {
    return this -> mes;
}

const int &calendario::get_ano() const {
    return this -> ano;
}

const int dia_mais_antigo(calendario c1, calendario c2) {
    int dif = c1.get_dia() - c2.get_dia();
    if(dif > 0) return -1;
    else if(dif < 0) return 1;
    else return 0;
}

const int mes_mais_antigo(calendario c1, calendario c2) {
    int dif = c1.get_mes() - c2.get_mes();
    if(dif > 0) return -1;
    else if(dif < 0) return 1;
    else return dia_mais_antigo(c1, c2);
}

const int calendario_mais_antigo(calendario c1, calendario c2) {
    int dif = c1.get_ano() - c2.get_ano();
    if(dif > 0) return -1;
    else if(dif < 0) return 1;
    else return mes_mais_antigo(c1, c2);
}

const int calendario_diferenca_anos(calendario c1, calendario c2) {
    if(c2.get_mes() > c1.get_mes()) return c2.get_ano() - c1.get_ano();
    else if(c2.get_mes() == c1.get_mes() && c2.get_dia() >= c1.get_dia()) return c2.get_ano() - c1.get_ano();
    else return c2.get_ano() - c1.get_ano() - 1;
}

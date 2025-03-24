#include "data.hpp"

const int &data::get_dia() const {
    return this -> dia;
}

const int &data::get_mes() const {
    return this -> mes;
}

const int &data::get_ano() const {
    return this -> ano;
}

const int dia_mais_antigo(data d1, data d2) {
    int dif = d1.get_dia() - d2.get_dia();
    if(dif > 0) return -1;
    else if(dif < 0) return 1;
    else return 0;
}

const int mes_mais_antigo(data d1, data d2) {
    int dif = d1.get_mes() - d2.get_mes();
    if(dif > 0) return -1;
    else if(dif < 0) return 1;
    else return dia_mais_antigo(d1, d2);
}

const int data_mais_antiga(data d1, data d2) {
    int dif = d1.get_ano() - d2.get_ano();
    if(dif > 0) return -1;
    else if(dif < 0) return 1;
    else return mes_mais_antigo(d1, d2);
}

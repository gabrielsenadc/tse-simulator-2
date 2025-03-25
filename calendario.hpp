#ifndef calendario_hpp
#define calendario_hpp

#include <string>

class calendario {

    int dia;
    int mes;
    int ano;

    public:
    
    calendario(const int dia, const int mes, const int ano): dia(dia), mes(mes), ano(ano) {};

    const int &get_dia() const;

    const int &get_mes() const;

    const int &get_ano() const;

};

const int calendario_mais_antigo(calendario c1, calendario c2);

const int calendario_diferenca_anos(calendario c1, calendario c2);

#endif


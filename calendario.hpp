#ifndef calendario_hpp
#define calendario_hpp

#include <string>

class calendario {

    int dia;
    int mes;
    int ano;

    public:
    
    calendario(const int dia, const int mes, const int ano);

    const int &get_dia() const;

    const int &get_mes() const;

    const int &get_ano() const;

};

const int calendario_mais_antigo(calendario d1, calendario d2);

#endif


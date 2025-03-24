#ifndef data_hpp
#define data_hpp

#include <string>

class data {

    int dia;
    int mes;
    int ano;

    public:
    
    data(const int dia, const int mes, const int ano);

    const int &get_dia() const;

    const int &get_mes() const;

    const int &get_ano() const;

};

const int data_mais_antiga(data d1, data d2);

#endif


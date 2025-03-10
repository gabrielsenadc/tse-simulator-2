#ifndef criptanalista_h
#define criptanalista_h

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class criptanalista {

    ifstream arquivo;
    istringstream linha_atual;

    public:
    
    criptanalista(const string path);

    const string &get_next(char parametro);

    void next_linha();

    void muda_arquivo(const string new_path);

    void fecha_arquivo();

};

#endif
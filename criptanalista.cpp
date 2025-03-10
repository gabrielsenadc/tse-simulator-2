#include "criptanalista.hpp"

criptanalista::criptanalista(const string path) {

    this -> arquivo.open(path);
    string linha;
    getline(this -> arquivo, linha);
    this -> linha_atual = istringstream(linha);

}

const string &criptanalista::get_next(char parametro) {

    string linha;
    getline(this -> linha_atual, linha, parametro);
    
return linha;
}

void criptanalista::next_linha() {

    string linha;
    getline(this -> arquivo, linha);
    this -> linha_atual = istringstream(linha);

}

void criptanalista::muda_arquivo(const string new_path) {

    this -> arquivo.close();
    this -> arquivo.open(new_path);
    string linha;
    getline(this -> arquivo, linha);
    this -> linha_atual = istringstream(linha);

}

void criptanalista::fecha_arquivo() {
    this -> arquivo.close();
}
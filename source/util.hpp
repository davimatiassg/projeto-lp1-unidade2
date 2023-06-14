#ifndef UTIL_H
#define UTIL_H

#include <string>

struct Data {
    int ano, mes, dia;
};

struct Endereco {
    std::string cidade, bairro, rua, cep;
    int numero;
};

#endif
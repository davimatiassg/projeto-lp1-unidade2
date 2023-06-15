#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <sstream>

namespace util{
    
    struct Data {
        int ano, mes, dia;
    };

    struct Endereco {
        std::string cidade, bairro, rua, cep;
        int numero;
    };
    std::string formatarData(Data);
    
    std::string formatarEndereco(Endereco);
}

#endif
//#include "Empresa.hpp"
#include <iostream>
#include <string>
#include <vector>
#include "Pessoa.hpp"
#include "Funcionario.hpp"
#include "Vendedor.hpp"
#include "Gerente.hpp"
#include "Empresa.hpp"

int main() {
    Empresa * empresa = new Empresa();
    empresa->carregarFuncoes();
    std::cout<< "tudo ok meu patrao";
    return 0;
}
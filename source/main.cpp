//#include "Empresa.hpp"
#include <iostream>
#include <string>
#include <vector>
#include "include\Pessoa.hpp"
#include "include\Funcionario.hpp"
#include "include\Vendedor.hpp"
#include "include\Gerente.hpp"
#include "include\Empresa.hpp"

int main() {
    Empresa * empresa = new Empresa();
    empresa->carregarFuncoes();
    std::cout<< "Operacoes do RH concluidas com sucesso. Pressione qualquer tecla para fechar.";
    char c;
    std::cin >> c;
    return 0;
}
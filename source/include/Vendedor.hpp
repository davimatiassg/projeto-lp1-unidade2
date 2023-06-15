#ifndef VENDEDOR_HPP
#define VENDEDOR_HPP

#include <string>
#include <iostream>
#include "Pessoa.hpp"
#include "Funcionario.hpp"

// Definição da classe concreta Vendedor
class Vendedor : public Pessoa, public Funcionario {
private:
    char tipoVendedor;

public:
    Vendedor();

    Vendedor(std::string, std::string, util::Data, util::Endereco, std::string, int, float, std::string, util::Data, char);

    // Getters e Setters
    char getTipoVendedor() const;

    void setTipoVendedor(char);

    float calcularSalario() override;

    float calcularRecisao(util::Data) override;

    void imprimirVendedor();
};

#endif
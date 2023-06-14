#ifndef VENDEDOR_HPP
#define VENDEDOR_HPP

#include <string>
#include "util.hpp"
#include "Pessoa.hpp"
#include "Funcionario.hpp"

// Definição da classe concreta Vendedor
class Vendedor : public Pessoa, public Funcionario {
private:
    char tipoVendedor;

public:
    Vendedor();

    Vendedor(std::string, std::string, Data, Endereco, std::string, int, float, std::string, Data, char);

    // Getters e Setters
    char getTipoVendedor() const;

    void setTipoVendedor(char);

    float calcularSalario(int) override;

    float calcularRecisao(Data) override;
};

#endif
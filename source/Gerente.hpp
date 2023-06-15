#ifndef GERENTE_HPP
#define GERENTE_HPP

#include <iostream>
#include <string>
#include "Pessoa.hpp"
#include "Funcionario.hpp"

// Definição da classe concreta Gerente
class Gerente : public Pessoa, public Funcionario {
private:
    float participacaoLucros;

public:
    Gerente();

    Gerente(std::string, std::string, util::Data, util::Endereco, std::string, int, float, std::string, util::Data, float);

    // Getters e Setters
    float getParticipacaoLucros() const;

    void setParticipacaoLucros(float);

    float calcularSalario() override;

    float calcularRecisao(util::Data) override;

    void imprimirGerente();
};

#endif
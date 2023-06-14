#ifndef GERENTE_HPP
#define GERENTE_HPP

#include <string>
#include "util.hpp"
#include "Pessoa.hpp"
#include "Funcionario.hpp"

// Definição da classe concreta Gerente
class Gerente : public Pessoa, public Funcionario {
private:
    float participacaoLucros;

public:
    Gerente();

    Gerente(std::string, std::string, Data, Endereco, std::string, int, float, std::string, Data, float);

    // Getters e Setters
    float getParticipacaoLucros() const;

    void setParticipacaoLucros(float);

    float calcularSalario(int diasFaltas) override;

    float calcularRecisao(Data desligamento) override;
};

#endif
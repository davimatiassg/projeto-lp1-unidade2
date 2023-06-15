#ifndef ASG_HPP
#define ASG_HPP

#include <iostream>
#include <string>
#include "Pessoa.hpp"
#include "Funcionario.hpp"

//Definição da classe Asg
class Asg : public Pessoa, public Funcionario {
private:
    float adicionalInsalubridade;

public:
    Asg();

    Asg(std::string, std::string, util::Data, util::Endereco, std::string, int, float, std::string, util::Data, float);

    // Getters e Setters
    float getAdicionalInsalubridade() const;

    void setAdicionalInsalubridade(float);

    float calcularSalario() override;
    float calcularRecisao(util::Data) override;

    void imprimirAsg();
};

#endif
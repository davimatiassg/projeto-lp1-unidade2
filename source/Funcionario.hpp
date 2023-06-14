#ifndef FUNCIONARIO_HPP
#define FUNCIONARIO_HPP

#include <string>
#include "util.hpp"

// Declaração de funcionário (abstrato):
class Funcionario {
private:
    float salario;
    std::string matricula;
    Data ingressoEmpresa;

public:
    // Getters e Setters
    float getSalario();
    std::string getMatricula();
    Data getIngressoEmpresa();

    void setSalario(float salario);
    void setMatricula(std::string matricula);
    void setIngressoEmpresa(Data ingressoEmpresa);

    virtual float calcularSalario(int diasFaltas) = 0;
    virtual float calcularRecisao(Data desligamento) = 0;
};

#endif
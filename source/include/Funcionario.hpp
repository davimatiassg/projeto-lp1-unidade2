#ifndef FUNCIONARIO_HPP
#define FUNCIONARIO_HPP

#include <string>
#include <iostream>
#include "util.hpp"

// Declaração de funcionário (abstrato):
class Funcionario {
private:
    float salario;
    std::string matricula;
    util::Data ingressoEmpresa;
    int numeroFaltas = 0;

public:
    // Getters e Setters
    float getSalario();
    std::string getMatricula();
    util::Data getIngressoEmpresa();
    int getNumeroFaltas();

    void setSalario(float);
    void setMatricula(std::string);
    void setIngressoEmpresa(util::Data);
    void setNumeroFaltas(int);

    virtual float calcularSalario() = 0;
    virtual float calcularRecisao(util::Data) = 0;

    void imprimirFuncionario();
};

#endif
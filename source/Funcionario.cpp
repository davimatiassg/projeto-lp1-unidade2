#include <string>
#include "Funcionario.hpp"

float Funcionario::getSalario() { return salario; }
std::string Funcionario::getMatricula() { return matricula; }
Data Funcionario::getIngressoEmpresa() { return ingressoEmpresa; }

void Funcionario::setSalario(float salario) { this->salario = salario; }
void Funcionario::setMatricula(std::string matricula) { this->matricula = matricula; }
void Funcionario::setIngressoEmpresa(Data ingressoEmpresa) { this->ingressoEmpresa = ingressoEmpresa; }

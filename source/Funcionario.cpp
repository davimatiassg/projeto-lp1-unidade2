#include <string>
#include <iostream>
#include "include\Funcionario.hpp"
#include "include\util.hpp"

float Funcionario::getSalario() { return salario; }
std::string Funcionario::getMatricula() { return matricula; }
util::Data Funcionario::getIngressoEmpresa() { return ingressoEmpresa; }
int Funcionario::getNumeroFaltas() { return numeroFaltas; }

void Funcionario::setSalario(float salario) { this->salario = salario; }
void Funcionario::setMatricula(std::string matricula) { this->matricula = matricula; }
void Funcionario::setIngressoEmpresa(util::Data ingressoEmpresa) { this->ingressoEmpresa = ingressoEmpresa; }
void Funcionario::setNumeroFaltas(int numeroFaltas) { this->numeroFaltas = numeroFaltas; }

void Funcionario::imprimirFuncionario()
{
	std::cout<<"Matricula: " <<matricula <<"\nData de ingresso: "<< util::formatarData(ingressoEmpresa);
	std::cout<<"\nSalario: "<< salario << "\nFaltas:" << numeroFaltas << ".\n";
}
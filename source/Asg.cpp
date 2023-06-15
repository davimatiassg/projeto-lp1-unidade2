#include <string>
#include <iostream>
#include "include\Pessoa.hpp"
#include "include\Funcionario.hpp"
#include "include\Asg.hpp"

//Implementação da classe Asg
Asg::Asg() {};

Asg::Asg(std::string nome, std::string cpf, util::Data dataNascimento, util::Endereco enderecoPessoal, std::string estadoCivil, int qtdFilhos, float salario, std::string matricula, util::Data ingressoEmpresa, float adicionalInsalubridade) : Pessoa(nome, cpf, dataNascimento, enderecoPessoal, estadoCivil, qtdFilhos), Funcionario(), adicionalInsalubridade(adicionalInsalubridade) {
    setSalario(salario);
    setMatricula(matricula);
    setIngressoEmpresa(ingressoEmpresa);
}

// Getters e Setters
float Asg::getAdicionalInsalubridade() const { return adicionalInsalubridade; }

void Asg::setAdicionalInsalubridade(float adicionalInsalubridade) { this->adicionalInsalubridade = adicionalInsalubridade; }

float Asg::calcularSalario() {
    float salario = getSalario();
    salario *= (30-getNumeroFaltas())/30;
    salario *= (getAdicionalInsalubridade()+1);
    salario += getQtdFilhos()*100;
    return salario;
}

float Asg::calcularRecisao(util::Data desligamento){
    util::Data ingresso = getIngressoEmpresa();
    int in = ingresso.ano*365 + ingresso.mes*30 + ingresso.dia;
    int ds = desligamento.ano*365 + desligamento.mes*30 + desligamento.dia;
    return getSalario() * (int)((ds-in)/365);
}


void Asg::imprimirAsg()
{
    imprimirPessoa();
    imprimirFuncionario();
    std::cout<<"Adicional de insalubridade: " << getAdicionalInsalubridade()*100 <<"%\n\n";
}
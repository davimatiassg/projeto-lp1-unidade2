#include <string>
#include "util.hpp"
#include "Pessoa.hpp"
#include "Funcionario.hpp"
#include "Asg.hpp"

//Implementação da classe Asg
Asg::Asg() {};

Asg::Asg(std::string nome, std::string cpf, Data dataNascimento, Endereco enderecoPessoal, std::string estadoCivil, int qtdFilhos, float salario, std::string matricula, Data ingressoEmpresa, float adicionalInsalubridade) : Pessoa(nome, cpf, dataNascimento, enderecoPessoal, estadoCivil, qtdFilhos), Funcionario(), adicionalInsalubridade(adicionalInsalubridade) {
    setSalario(salario);
    setMatricula(matricula);
    setIngressoEmpresa(ingressoEmpresa);
}

// Getters e Setters
float Asg::getAdicionalInsalubridade() const { return adicionalInsalubridade; }

void Asg::setAdicionalInsalubridade(float adicionalInsalubridade) { this->adicionalInsalubridade = adicionalInsalubridade; }

float Asg::calcularSalario(int diasFaltas) {
    float salario = getSalario();
    salario *= (30-diasFaltas)/30;
    salario *= (getAdicionalInsalubridade()+1);
    salario += getQtdFilhos()*100;
    return salario;
}

float Asg::calcularRecisao(Data desligamento){
    Data ingresso = getIngressoEmpresa();
    int in = ingresso.ano*365 + ingresso.mes*30 + ingresso.dia;
    int ds = desligamento.ano*365 + desligamento.mes*30 + desligamento.dia;
    return calcularSalario(0) * (int)((in-ds)/365);
}



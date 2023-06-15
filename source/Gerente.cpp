#include <string>
#include <iostream>
#include "Gerente.hpp"
#include "Pessoa.hpp"
#include "Funcionario.hpp"

// Implementação da classe concreta Vendedor
Gerente::Gerente() {};

Gerente::Gerente(std::string nome, std::string cpf, util::Data dataNascimento, util::Endereco enderecoPessoal, std::string estadoCivil, int qtdFilhos, float salario, std::string matricula, util::Data ingressoEmpresa, float ptLucros) : Pessoa(nome, cpf, dataNascimento, enderecoPessoal, estadoCivil, qtdFilhos), Funcionario(), participacaoLucros(ptLucros)
{

	setSalario(salario);
    setMatricula(matricula);
    setIngressoEmpresa(ingressoEmpresa);
}

    // Getters e Setters
float Gerente::getParticipacaoLucros() const { return participacaoLucros; }

void Gerente::setParticipacaoLucros(float participacaoLucros) { this->participacaoLucros = participacaoLucros; }

float Gerente::calcularSalario() {
    float salario = getSalario();
    salario *= (30-getNumeroFaltas())/30;
    salario += participacaoLucros;
    salario += getQtdFilhos()*100;
    return salario;
}

float Gerente::calcularRecisao(util::Data desligamento) {
    util::Data ingresso = getIngressoEmpresa();
    int in = ingresso.ano*365 + ingresso.mes*30 + ingresso.dia;
    int ds = desligamento.ano*365 + desligamento.mes*30 + desligamento.dia;
    return getSalario() * (int)((in-ds)/365);
}

void Gerente::imprimirGerente()
{
    imprimirPessoa();
    imprimirFuncionario();
    std::cout<<"Participacao nos Lucros " << getParticipacaoLucros() <<std::endl;
}

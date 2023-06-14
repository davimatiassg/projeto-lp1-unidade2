#include "Gerente.hpp"
#include "Pessoa.hpp"
#include "Funcionario.hpp"
#include <string>

// Implementação da classe concreta Vendedor
Gerente::Gerente() {};

Gerente::Gerente(std::string nome, std::string cpf, Data dataNascimento, Endereco enderecoPessoal, std::string estadoCivil, int qtdFilhos, float salario, std::string matricula, Data ingressoEmpresa, float ptLucros) : Pessoa(nome, cpf, dataNascimento, enderecoPessoal, estadoCivil, qtdFilhos), Funcionario(), participacaoLucros(ptLucros)
{

	setSalario(salario);
    setMatricula(matricula);
    setIngressoEmpresa(ingressoEmpresa);
}

    // Getters e Setters
float Gerente::getParticipacaoLucros() const { return participacaoLucros; }

void Gerente::setParticipacaoLucros(float participacaoLucros) { this->participacaoLucros = participacaoLucros; }

float Gerente::calcularSalario(int diasFaltas) {
    // Implementação do cálculo do salário para Gerente
    return 0.0;
}

float Gerente::calcularRecisao(Data desligamento) {
    // Implementação do cálculo da rescisão para Gerente
    return 0.0f;
}

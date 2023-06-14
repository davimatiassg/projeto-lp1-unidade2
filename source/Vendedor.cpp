#include <string>
#include "util.hpp"
#include "Pessoa.hpp"
#include "Funcionario.hpp"
#include "Vendedor.hpp"

// Implementação da classe concreta Vendedor
Vendedor::Vendedor() {};
Vendedor::Vendedor(std::string nome, std::string cpf, Data dataNascimento, Endereco enderecoPessoal, std::string estadoCivil, int qtdFilhos, float salario, std::string matricula, Data ingressoEmpresa, char tipoVendedor) : Pessoa(nome, cpf, dataNascimento, enderecoPessoal, estadoCivil, qtdFilhos), Funcionario(), tipoVendedor(tipoVendedor) {
    setSalario(salario);
    setMatricula(matricula);
    setIngressoEmpresa(ingressoEmpresa);
}

// Getters e Setters
char Vendedor::getTipoVendedor() const { return tipoVendedor; }

void Vendedor::setTipoVendedor(char tipoVendedor) { this->tipoVendedor = tipoVendedor; }

float Vendedor::calcularSalario(int diasFaltas){
    float salario = getSalario();
    char t = getTipoVendedor();
    float grat = t == 'a' ? 0.25f : (t == 'b' ? 0.1f : 0.05f);
    salario *= (float)(30-diasFaltas)/30;
    salario *= (grat+1);
    salario += getQtdFilhos()*100;
    return salario;
}

float Vendedor::calcularRecisao(Data desligamento){
    Data ingresso = getIngressoEmpresa();
    int in = ingresso.ano*365 + ingresso.mes*30 + ingresso.dia;
    int ds = desligamento.ano*365 + desligamento.mes*30 + desligamento.dia;
    return calcularSalario(0) * (int)((in-ds)/365);
}
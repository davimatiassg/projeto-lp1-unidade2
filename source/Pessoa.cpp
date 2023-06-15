#include <string>
#include <iostream>
#include "Pessoa.hpp"

// Implementação da classe concreta Pessoa
Pessoa::Pessoa() {};

Pessoa::Pessoa(std::string n, std::string c, util::Data d, util::Endereco e, std::string est, int qtd){
    this->nome = n; 
    this->cpf = c;
    this->dataNascimento = d;
    this->enderecoPessoal = e;
    this->estadoCivil = est;
    this->qtdFilhos = qtd;
}

// Getters e Setters
std::string Pessoa::getNome(){ return nome; }
std::string Pessoa::getCPF(){ return cpf; }
util::Data Pessoa::getDataNascimento(){ return dataNascimento; }
util::Endereco Pessoa::getEnderecoPessoal(){ return enderecoPessoal; }
std::string Pessoa::getEstadoCivil(){ return estadoCivil; }
int Pessoa::getQtdFilhos(){ return qtdFilhos; }

void Pessoa::setNome(std::string nome) { this->nome = nome; }
void Pessoa::setCPF(std::string cpf) { this->cpf = cpf; }
void Pessoa::setDataNascimento(util::Data dataNascimento) { this->dataNascimento = dataNascimento; }
void Pessoa::setEnderecoPessoal(util::Endereco enderecoPessoal) { this->enderecoPessoal = enderecoPessoal; }
void Pessoa::setEstadoCivil(std::string estadoCivil) { this->estadoCivil = estadoCivil; }
void Pessoa::setQtdFilhos(int qtdFilhos) { this->qtdFilhos = qtdFilhos; }


// Print
void Pessoa::imprimirPessoa()
{
    std::cout<< "Nome: " << nome << "\nCPF: " << cpf << "\nData de nascimento: " << util::formatarData(dataNascimento);
    std::cout <<"\nEndereco: " << util::formatarEndereco(enderecoPessoal) << "\nEstado Civil: " << estadoCivil << "\nFilhos: " << qtdFilhos <<".\n";
}


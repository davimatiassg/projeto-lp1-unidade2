#include <string>
#include "Pessoa.hpp"

// Implementação da classe concreta Pessoa
Pessoa::Pessoa() {};

Pessoa::Pessoa(std::string n, std::string c, Data d, Endereco e, std::string est, int qtd){
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
Data Pessoa::getDataNascimento(){ return dataNascimento; }
Endereco Pessoa::getEnderecoPessoal(){ return enderecoPessoal; }
std::string Pessoa::getEstadoCivil(){ return estadoCivil; }
int Pessoa::getQtdFilhos(){ return qtdFilhos; }

void Pessoa::setNome(std::string nome) { this->nome = nome; }
void Pessoa::setCPF(std::string cpf) { this->cpf = cpf; }
void Pessoa::setDataNascimento(Data dataNascimento) { this->dataNascimento = dataNascimento; }
void Pessoa::setEnderecoPessoal(Endereco enderecoPessoal) { this->enderecoPessoal = enderecoPessoal; }
void Pessoa::setEstadoCivil(std::string estadoCivil) { this->estadoCivil = estadoCivil; }
void Pessoa::setQtdFilhos(int qtdFilhos) { this->qtdFilhos = qtdFilhos; }



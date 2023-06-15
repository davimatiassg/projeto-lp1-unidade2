#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <string>
#include <iostream>
#include "util.hpp"


// Declaração da classe concreta Pessoa
class Pessoa {
private:
    std::string nome;
    std::string cpf;
    util::Data dataNascimento;
    util::Endereco enderecoPessoal;
    std::string estadoCivil;
    int qtdFilhos;

public:
	// Construtores
    Pessoa();

    Pessoa(std::string, std::string, util::Data, util::Endereco, std::string, int);


    // Getters e Setters
    std::string getNome();
    std::string getCPF();
    util::Data getDataNascimento();
    util::Endereco getEnderecoPessoal();
    std::string getEstadoCivil();
    int getQtdFilhos();

    void setNome(std::string);
    void setCPF(std::string);
    void setDataNascimento(util::Data);
    void setEnderecoPessoal(util::Endereco);
    void setEstadoCivil(std::string);
    void setQtdFilhos(int);


    //Print
    void imprimirPessoa();
};

#endif

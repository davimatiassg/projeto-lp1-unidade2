#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <string>
#include "util.hpp"


// Declaração da classe concreta Pessoa
class Pessoa {
private:
    std::string nome;
    std::string cpf;
    Data dataNascimento;
    Endereco enderecoPessoal;
    std::string estadoCivil;
    int qtdFilhos;

public:
	// Construtores
    Pessoa();

    Pessoa(std::string, std::string, Data, Endereco, std::string, int);


    // Getters e Setters
    std::string getNome();
    std::string getCPF();
    Data getDataNascimento();
    Endereco getEnderecoPessoal();
    std::string getEstadoCivil();
    int getQtdFilhos();

    void setNome(std::string);
    void setCPF(std::string);
    void setDataNascimento(Data);
    void setEnderecoPessoal(Endereco);
    void setEstadoCivil(std::string);
    void setQtdFilhos(int);
};

#endif

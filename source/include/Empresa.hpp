#ifndef EMPRESA_HPP
#define EMPRESA_HPP

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include "util.hpp"
#include "Pessoa.hpp"
#include "Funcionario.hpp"
#include "Asg.hpp"
#include "Vendedor.hpp"
#include "Gerente.hpp"
#include "Empresa.hpp"

using namespace std;

// Definição da classe Empresa
class Empresa {
private:
    float faturamentoMensal;
    string nomeEmpresa;
    string cnpj;
    Pessoa dono;
    vector<Asg> asgs;
    vector<Vendedor> vendedores;
    vector<Gerente> gerentes;

public:
    Empresa();

    Empresa(string, string, float);

    // Getters e Setters
    float getFaturamentoMensal() const;

    void setFaturamentoMensal(float);

    string getNomeEmpresa() const;

    void setNomeEmpresa(const string&);

    string getCnpj() const;

    void setCnpj(const string&);

    Pessoa getDono() const;

    void setDono(const Pessoa&);

    vector<Asg> getAsgs() const;

    void setAsgs(const vector<Asg>&) ;

    vector<Vendedor> getVendedores() const;

    void setVendedores(const vector<Vendedor>&);

    vector<Gerente> getGerentes() const;

    void setGerentes(const vector<Gerente>&);


    //Funções da empresa
    void carregarFuncoes();

    void carregarEmpresa();

    void carregarAsg();

    void carregarVendedor();

    void carregarGerente();

    void carregarDono();

    void imprimirAsgs();

    void imprimirVendedores();

    void imprimirGerentes();

    void imprimirDono();

    void buscarFuncionario(std::string );

    void calcularSalarioFuncionario(std::string);

    void calcularTodoOsSalarios();

    void calcularRecisaoFuncionario(std::string, util::Data);

    void calcularRecisaoTodosFuncionarios(util::Data);
};

#endif
#include <fstream>
#include <sstream>
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

Empresa::Empresa() {};

Empresa::Empresa(string nomeEmpresa, string cnpj, float faturamentoMensal) : faturamentoMensal(faturamentoMensal), nomeEmpresa(nomeEmpresa), cnpj(cnpj) {};

// Getters e Setters
float Empresa::getFaturamentoMensal() const { return faturamentoMensal; }

void Empresa::setFaturamentoMensal(float faturamentoMensal) { this->faturamentoMensal = faturamentoMensal; }

string Empresa::getNomeEmpresa() const { return nomeEmpresa; }

void Empresa::setNomeEmpresa(const string& nomeEmpresa) { this->nomeEmpresa = nomeEmpresa; }

string Empresa::getCnpj() const { return cnpj; }

void Empresa::setCnpj(const string& cnpj) { this->cnpj = cnpj; }

Pessoa Empresa::getDono() const { return dono; }

void Empresa::setDono(const Pessoa& dono) { this->dono = dono; }

vector<Asg> Empresa::getAsgs() const { return asgs; }

void Empresa::setAsgs(const vector<Asg>& asgs) { this->asgs = asgs; }

vector<Vendedor> Empresa::getVendedores() const { return vendedores; }

void Empresa::setVendedores(const vector<Vendedor>& vendedores) { this->vendedores = vendedores; }

vector<Gerente> Empresa::getGerentes() const { return gerentes; }

void Empresa::setGerentes(const vector<Gerente>& gerentes) { this->gerentes = gerentes; }

void Empresa::carregarFuncoes() {

    std::ifstream arquivo("../aula/arquivos para leitura/funcoes.txt");
    std::string linha;

    if (arquivo.is_open()) {
        while (std::getline(arquivo, linha)) {
            // Chamar a função correspondente à linha lida
            chamarFuncao(linha);
        }

        arquivo.close();
    } else {
        std::err << "Erro ao abrir o arquivo funcoes.txt" << std::endl;
    }


    std::istringstream iss(linha);
    std::string nomeFuncao;
    iss >> nomeFuncao;

    // Exemplo de como você pode verificar qual função deve ser chamada:
    if (nomeFuncao == "funcao1") {
        // Chamar a função funcao1()
        funcao1();
    } else if (nomeFuncao == "funcao2") {
        // Chamar a função funcao2()
        funcao2();
    } else {
        // Função desconhecida, faça o tratamento apropriado
        std::cout << "Função desconhecida: " << nomeFuncao << std::endl;
    }
}

void Empresa::carregarEmpresa() {
    // Implementação da leitura do arquivo empresa.txt e carregamento dos dados da empresa
}

void Empresa::carregarAsg() {
    // Implementação da leitura do arquivo asg.txt e carregamento dos dados dos ASGs
}

void Empresa::carregarVendedor() {
    // Implementação da leitura do arquivo vendedor.txt e carregamento dos dados dos Vendedores
}

void Empresa::carregarGerente() {
    // Implementação da leitura do arquivo gerente.txt e carregamento dos dados dos Gerentes
}

void Empresa::carregarDono() {
    // Implementação da leitura do arquivo dono.txt e carregamento dos dados do Dono
}

void Empresa::imprimirAsgs() {
    // Implementação da impressão de todos os atributos de todos os ASGs
}

void Empresa::imprimirVendedores() {
    // Implementação da impressão de todos os atributos de todos os Vendedores
}

void Empresa::imprimirGerentes() {
    // Implementação da impressão de todos os atributos de todos os Gerentes
}

void Empresa::imprimirDono() {
    // Implementação da impressão de todos os atributos do Dono
}

void Empresa::buscarFuncionario(int matricula) {
    // Implementação da busca de um funcionário pelo número de matrícula
}

void Empresa::calcularSalarioFuncionario(int matricula) {
    // Implementação do cálculo do salário de um funcionário pelo número de matrícula
}

void Empresa::calcularTodoOsSalarios() {
    // Implementação do cálculo de todos os salários e gravação em um arquivo
}

void Empresa::calcularRecisaoFuncionario(int matricula) {
    // Implementação do cálculo da rescisão de um funcionário pelo número de matrícula
}

void Empresa::calcularRecisaoTodosFuncionarios() {
    // Implementação do cálculo da rescisão de todos os funcionários e gravação em um arquivo
}

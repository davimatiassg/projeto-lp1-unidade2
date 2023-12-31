#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include "include\util.hpp"
#include "include\Pessoa.hpp"
#include "include\Funcionario.hpp"
#include "include\Asg.hpp"
#include "include\Vendedor.hpp"
#include "include\Gerente.hpp"
#include "include\Empresa.hpp"

using namespace std;


//Variavel global que armazena a data de hoje




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


// Métodos de carregamento de arquivos
void Empresa::carregarFuncoes() {

    std::ifstream arquivo("../arquivos para leitura/funcoes.txt");
    std::string linha;

    if (arquivo.is_open()) 
    {
        while (std::getline(arquivo, linha)) 
        {
            std::istringstream iss(linha);
            std::string nomeFuncao;
            iss >> nomeFuncao;

            // Chamar cada funçao pelo nome:
            if (nomeFuncao == "carregarEmpresa()") {
                carregarEmpresa();
            } else if (nomeFuncao == "carregarAsg()") {
                carregarAsg();
            } else if (nomeFuncao == "carregarVendedor()") {
                carregarVendedor();
            } else if (nomeFuncao == "carregarGerente()") {
                carregarGerente();
            } else if (nomeFuncao == "carregarDono()") {
                carregarDono();

            } else if (nomeFuncao == "imprimirAsgs()") {
                imprimirAsgs();
            } else if (nomeFuncao == "imprimirVendedores()") {
                imprimirVendedores();
            } else if (nomeFuncao == "imprimirGerentes()") {
                imprimirGerentes();
            } else if (nomeFuncao == "imprimirDono()") {
                imprimirDono();

            } else if (nomeFuncao == "calcularTodoOsSalarios()") {
                calcularTodoOsSalarios();
            } else if (nomeFuncao == "buscarFuncionario()") {
                // Tentar ler a matricula do Funcionario 
                try{
                    std::getline(arquivo, linha);
                    buscarFuncionario(linha);

                } catch (const std::exception& e) {
                    std::cout << "Tivemos um erro: " << e.what() << std::endl;
                }
                
            } else if (nomeFuncao == "calcularSalarioFuncionario()") {
                try
                {
                    std::getline(arquivo, linha);
                    calcularSalarioFuncionario(linha);
                }
                    catch (const std::exception& e) {
                    // Tratar exceçao genérica
                    std::cout << "Tivemos um erro: " << e.what() << std::endl;
                }
            } else if (nomeFuncao == "calcularRecisaoFuncionario()") {
                try
                {
                    std::getline(arquivo, linha);
                    std::string matr = linha;

                    util::Data dt;
                    std::getline(arquivo, linha);
                    dt.ano = std::stoi(linha);
                    std::getline(arquivo, linha);
                    dt.mes = std::stoi(linha);
                    std::getline(arquivo, linha);
                    dt.dia = std::stoi(linha);

                    calcularRecisaoFuncionario(matr, dt);
                }
                    catch (const std::exception& e) {
                    // Tratar exceçao genérica
                    std::cout << "Tivemos um erro: " << e.what() << std::endl;
                }

            } else if (nomeFuncao == "calcularTodasAsRecisoes()") {
                try
                {
                    util::Data dt;

                    std::getline(arquivo, linha);
                    dt.ano = std::stoi(linha);
                    std::getline(arquivo, linha);
                    dt.mes = std::stoi(linha);
                    std::getline(arquivo, linha);
                    dt.dia = std::stoi(linha);

                    calcularRecisaoTodosFuncionarios(dt);
                }
                    catch (const std::exception& e) {
                    // Tratar exceçao genérica
                    std::cout << "Tivemos um erro: " << e.what() << std::endl;
                }

            } else {
                // Funçao desconhecida, faça o tratamento apropriado
                std::cout << "Funçao desconhecida: " << nomeFuncao << std::endl;
            }
        }
        arquivo.close();
    } else {
        std::cout << "Erro ao abrir o arquivo funcoes.txt" << std::endl;
    }
}

void Empresa::carregarEmpresa() {
    std::ifstream arquivo("../arquivos para leitura/empresa.txt"); // Abre o arquivo para leitura
    std::string linha;

    if (arquivo.is_open()) {
        while (std::getline(arquivo, linha)) {
            if (linha.find("#") != std::string::npos) {
                continue; // Ignora linhas que contenham "#""
            }
            try {
                setNomeEmpresa(linha);

                std::getline(arquivo, linha);
                setCnpj(linha);

                std::getline(arquivo, linha);
                setFaturamentoMensal(std::stoi(linha));
            
            } catch (const std::exception& e) {

            }
        }

        arquivo.close(); // Fecha o arquivo
    } else {
        std::cout << "Erro ao abrir o arquivo." << std::endl;
    }
}

void Empresa::carregarAsg() {
    std::ifstream arquivo("../arquivos para leitura/asg.txt"); // Abre o arquivo para leitura
    std::string linha;

    if (arquivo.is_open()) {

        while (std::getline(arquivo, linha)) {
            //quando encontrar uma linha que declare o inicio dos dados de um ASG:
            if (linha.find("ASG Nº") != std::string::npos) { 
                Asg * new_func = new Asg();
                std::getline(arquivo, linha);
                // tentar criar um objeto do tipo ASG com os parâmetros do arquivo
                try{
                    std::getline(arquivo, linha);
                    new_func->setNome(linha);

                    std::getline(arquivo, linha);
                    new_func->setCPF(linha);

                    std::getline(arquivo, linha);
                    new_func->setQtdFilhos(std::stoi(linha));

                    std::getline(arquivo, linha);
                    new_func->setEstadoCivil(linha);


                } catch (const std::exception& e) {
                    std::cout << "Tivemos um erro na leitura da Pessoa: " << e.what() << std::endl;
                } try{
                    util::Endereco end;
                    std::getline(arquivo, linha);

                    std::getline(arquivo, linha);
                    end.cidade = linha;
                    std::getline(arquivo, linha);
                    end.cep = linha;
                    std::getline(arquivo, linha);
                    end.bairro = linha;
                    std::getline(arquivo, linha);
                    end.rua = linha;
                    std::getline(arquivo, linha);
                    end.numero = std::stoi(linha);

                    new_func->setEnderecoPessoal(end);

                } catch (const std::exception& e) {
                    std::cout << "Tivemos um erro na leitura do Endereço: " << e.what() << std::endl;
                }

                try{
                    util::Data d;
                    std::getline(arquivo, linha);

                    std::getline(arquivo, linha);
                    d.ano = std::stoi(linha);
                    std::getline(arquivo, linha);
                    d.mes = std::stoi(linha);
                    std::getline(arquivo, linha);
                    d.dia = std::stoi(linha);

                    new_func->setDataNascimento(d);

                } catch (const std::exception& e) {
                    std::cout << "Tivemos um erro na leitura da data de Nascimento: " << e.what() << std::endl;
                }

                try{
                    util::Data d;
                    std::getline(arquivo, linha);

                    std::getline(arquivo, linha);
                    new_func->setMatricula(linha);
                    std::getline(arquivo, linha);
                    new_func->setSalario(std::stof(linha));
                    std::getline(arquivo, linha);
                    new_func->setAdicionalInsalubridade(std::stof(linha));
                    std::getline(arquivo, linha);
                    new_func->setNumeroFaltas(std::stoi(linha));

                } catch (const std::exception& e) {
                    std::cout << "Tivemos um erro na leitura dos dados de funcionario ASG: " << e.what() << std::endl;
                }

                try{
                    util::Data d;
                    std::getline(arquivo, linha);

                    std::getline(arquivo, linha);
                    d.ano = std::stoi(linha);
                    std::getline(arquivo, linha);
                    d.mes = std::stoi(linha);
                    std::getline(arquivo, linha);
                    d.dia = std::stoi(linha);
                    
                    new_func->setIngressoEmpresa(d);

                } catch (const std::exception& e) {
                    std::cout << "Tivemos um erro na leitura da data de ingresso: " << e.what() << std::endl;
                }

                asgs.push_back(*new_func);
            }
        }

        arquivo.close(); // Fecha o arquivo
    } else {
        std::cout << "Erro ao abrir o arquivo." << std::endl;
    }
}

void Empresa::carregarVendedor() {

    std::ifstream arquivo("../arquivos para leitura/vendedor.txt"); // Abre o arquivo para leitura
    std::string linha;

    if (arquivo.is_open()) {

        while (std::getline(arquivo, linha)) {
            //quando encontrar uma linha que declare o inicio dos dados de um Vendedor:
            if (linha.find("VENDEDOR Nº") != std::string::npos) { 
                Vendedor * new_func = new Vendedor();
                std::getline(arquivo, linha);
                try{
                    std::getline(arquivo, linha);
                    new_func->setNome(linha);

                    std::getline(arquivo, linha);
                    new_func->setCPF(linha);


                    std::getline(arquivo, linha);
                    new_func->setQtdFilhos(std::stoi(linha));

                    std::getline(arquivo, linha);
                    new_func->setEstadoCivil(linha);

                } catch (const std::exception& e) {
                    std::cout << "Tivemos um erro na leitura da Pessoa: " << e.what() << std::endl;
                } try{
                    util::Endereco end;
                    std::getline(arquivo, linha);

                    std::getline(arquivo, linha);
                    end.cidade = linha;
                    std::getline(arquivo, linha);
                    end.cep = linha;
                    std::getline(arquivo, linha);
                    end.bairro = linha;
                    std::getline(arquivo, linha);
                    end.rua = linha;
                    std::getline(arquivo, linha);
                    end.numero = std::stoi(linha);

                    new_func->setEnderecoPessoal(end);

                } catch (const std::exception& e) {
                    std::cout << "Tivemos um erro na leitura do Endereço: " << e.what() << std::endl;
                }

                try{
                    util::Data d;
                    std::getline(arquivo, linha);

                    std::getline(arquivo, linha);
                    d.ano = std::stoi(linha);
                    std::getline(arquivo, linha);
                    d.mes = std::stoi(linha);
                    std::getline(arquivo, linha);
                    d.dia = std::stoi(linha);

                    new_func->setDataNascimento(d);

                } catch (const std::exception& e) {
                    std::cout << "Tivemos um erro na leitura da data de Nascimento: " << e.what() << std::endl;
                }

                try{
                    util::Data d;
                    std::getline(arquivo, linha);

                    std::getline(arquivo, linha);
                    new_func->setMatricula(linha);
                    std::getline(arquivo, linha);
                    new_func->setSalario(std::stof(linha));
                    std::getline(arquivo, linha);
                    new_func->setTipoVendedor(linha[0]);
                    std::getline(arquivo, linha);
                    new_func->setNumeroFaltas(std::stoi(linha));

                } catch (const std::exception& e) {
                    std::cout << "Tivemos um erro na leitura dos dados de funcionario Vendedor: " << e.what() << std::endl;
                }

                try{
                    util::Data d;
                    std::getline(arquivo, linha);

                    std::getline(arquivo, linha);
                    d.ano = std::stoi(linha);
                    std::getline(arquivo, linha);
                    d.mes = std::stoi(linha);
                    std::getline(arquivo, linha);
                    d.dia = std::stoi(linha);
                    
                    new_func->setIngressoEmpresa(d);

                } catch (const std::exception& e) {
                    std::cout << "Tivemos um erro na leitura da data de ingresso: " << e.what() << std::endl;
                }

                vendedores.push_back(*new_func);
            }
        }

        arquivo.close(); // Fecha o arquivo
    } else {
        std::cout << "Erro ao abrir o arquivo." << std::endl;
    }
}

void Empresa::carregarGerente() {
    std::ifstream arquivo("../arquivos para leitura/gerente.txt"); // Abre o arquivo para leitura
    std::string linha;

    if (arquivo.is_open()) {

        while (std::getline(arquivo, linha)) {
            //quando encontrar uma linha que declare o inicio dos dados de um ASG:
            if (linha.find("GERENTE Nº") != std::string::npos) { 
                Gerente * new_func = new Gerente();
                std::getline(arquivo, linha);
                
                try{
                    std::getline(arquivo, linha);
                    new_func->setNome(linha);

                    std::getline(arquivo, linha);
                    new_func->setCPF(linha);

                    std::getline(arquivo, linha);
                    new_func->setQtdFilhos(std::stoi(linha));

                    std::getline(arquivo, linha);
                    new_func->setEstadoCivil(linha);

                } catch (const std::exception& e) {
                    std::cout << "Tivemos um erro na leitura da Pessoa: " << e.what() << std::endl;
                } try{
                    util::Endereco end;
                    std::getline(arquivo, linha);

                    std::getline(arquivo, linha);
                    end.cidade = linha;
                    std::getline(arquivo, linha);
                    end.cep = linha;
                    std::getline(arquivo, linha);
                    end.bairro = linha;
                    std::getline(arquivo, linha);
                    end.rua = linha;
                    std::getline(arquivo, linha);
                    end.numero = std::stoi(linha);

                    new_func->setEnderecoPessoal(end);

                } catch (const std::exception& e) {
                    std::cout << "Tivemos um erro na leitura do Endereço: " << e.what() << std::endl;
                }

                try{
                    util::Data d;
                    std::getline(arquivo, linha);

                    std::getline(arquivo, linha);
                    d.ano = std::stoi(linha);
                    std::getline(arquivo, linha);
                    d.mes = std::stoi(linha);
                    std::getline(arquivo, linha);
                    d.dia = std::stoi(linha);

                    new_func->setDataNascimento(d);

                } catch (const std::exception& e) {
                    std::cout << "Tivemos um erro na leitura da data de Nascimento: " << e.what() << std::endl;
                }

                try{
                    util::Data d;
                    std::getline(arquivo, linha);

                    std::getline(arquivo, linha);
                    new_func->setMatricula(linha);
                    std::getline(arquivo, linha);
                    new_func->setSalario(std::stof(linha));
                    std::getline(arquivo, linha);
                    new_func->setParticipacaoLucros(std::stof(linha));
                    std::getline(arquivo, linha);
                    new_func->setNumeroFaltas(std::stoi(linha));

                } catch (const std::exception& e) {
                    std::cout << "Tivemos um erro na leitura dos dados de funcionario Gerente: " << e.what() << std::endl;
                }

                try{
                    util::Data d;
                    std::getline(arquivo, linha);

                    std::getline(arquivo, linha);
                    d.ano = std::stoi(linha);
                    std::getline(arquivo, linha);
                    d.mes = std::stoi(linha);
                    std::getline(arquivo, linha);
                    d.dia = std::stoi(linha);
                    
                    new_func->setIngressoEmpresa(d);

                } catch (const std::exception& e) {
                    std::cout << "Tivemos um erro na leitura da data de ingresso: " << e.what() << std::endl;
                }

                gerentes.push_back(*new_func);
            }
        }

        arquivo.close(); // Fecha o arquivo
    } else {
        std::cout << "Erro ao abrir o arquivo." << std::endl;
    }
}

void Empresa::carregarDono() {
    
    std::ifstream arquivo("../arquivos para leitura/dono.txt"); // Abre o arquivo para leitura
    std::string linha;

    if (arquivo.is_open()) {
        Pessoa * new_func = new Pessoa();
        std::getline(arquivo, linha);
        std::getline(arquivo, linha);
        try{
            std::getline(arquivo, linha);
            new_func->setNome(linha);

            std::getline(arquivo, linha);
            new_func->setCPF(linha);

            std::getline(arquivo, linha);
            new_func->setQtdFilhos(std::stoi(linha));

            std::getline(arquivo, linha);
            new_func->setEstadoCivil(linha);

        } catch (const std::exception& e) {
            std::cout << "Tivemos um erro na leitura da Pessoa: " << e.what() << std::endl;
        } try{
            util::Endereco end;

            std::getline(arquivo, linha);
            end.cidade = linha;
            std::getline(arquivo, linha);
            end.cep = linha;
            std::getline(arquivo, linha);
            end.bairro = linha;
            std::getline(arquivo, linha);
            end.rua = linha;
            std::getline(arquivo, linha);
            end.numero = std::stoi(linha);

            new_func->setEnderecoPessoal(end);

        } catch (const std::exception& e) {
            std::cout << "Tivemos um erro na leitura do Endereço: " << e.what() << std::endl;
        }

        try{
            util::Data d;

            std::getline(arquivo, linha);
            d.ano = std::stoi(linha);
            std::getline(arquivo, linha);
            d.mes = std::stoi(linha);
            std::getline(arquivo, linha);
            d.dia = std::stoi(linha);

            new_func->setDataNascimento(d);

        } catch (const std::exception& e) {
            std::cout << "Tivemos um erro na leitura da data de Nascimento: " << e.what() << std::endl;
        }

        setDono(*new_func);
        arquivo.close(); // Fecha o arquivo
    } else {
        std::cout << "Erro ao abrir o arquivo." << std::endl;
    }
}



// Métodos de impressao
void Empresa::imprimirAsgs() {
    std::cout<<"imprimindo Asgs.\n";
    for(vector<Asg>::iterator it{asgs.begin()}; it != asgs.end(); it++)
    {
        it->imprimirAsg();
    }
}

void Empresa::imprimirVendedores() {
    std::cout<<"imprimindo Vendedores.\n";
    for(vector<Vendedor>::iterator it{vendedores.begin()}; it != vendedores.end(); it++)
    {
        it->imprimirVendedor();
    }
}

void Empresa::imprimirGerentes() {
    std::cout<<"imprimindo Gerentes.\n";
    for(vector<Gerente>::iterator it{gerentes.begin()}; it != gerentes.end(); it++)
    {
        it->imprimirGerente();
    }
}

void Empresa::imprimirDono() {
    std::cout<<"imprimindo Dono.\n";
    dono.imprimirPessoa();
    std::cout<<std::endl;
}


// Ações do RH
void Empresa::buscarFuncionario(std::string matricula) {
    std::cout<< "Buscando Funcionario:\n";
    for(vector<Gerente>::iterator it{gerentes.begin()}; it != gerentes.end(); it++)
    {
        if(it->getMatricula() == matricula)
        {
            it->imprimirGerente();
            return;
        }
    }
    for(vector<Vendedor>::iterator it{vendedores.begin()}; it != vendedores.end(); it++)
    {
        if(it->getMatricula() == matricula)
        {
            it->imprimirVendedor();
            return;
        }
    }
    for(vector<Asg>::iterator it{asgs.begin()}; it != asgs.end(); it++)
    {
        if(it->getMatricula() == matricula)
        {
            it->imprimirAsg();
            return;
        }
    }
    std::cout<< "Funcionario com matricula " << matricula << "nao encontrado no sistema.\n";
}

void Empresa::calcularSalarioFuncionario(std::string  matricula) {
    for(vector<Gerente>::iterator it{gerentes.begin()}; it != gerentes.end(); it++)
    {
        if(it->getMatricula() == matricula)
        {
            std::cout << "Salario do funcionario: " << it->calcularSalario() << " Reais.\n";
            return;
        }
    }
    for(vector<Vendedor>::iterator it{vendedores.begin()}; it != vendedores.end(); it++)
    {
        if(it->getMatricula() == matricula)
        {
            std::cout << "Salario do funcionario: " << it->calcularSalario() << " Reais.\n";
            return;
        }
    }
    for(vector<Asg>::iterator it{asgs.begin()}; it != asgs.end(); it++)
    {
        if(it->getMatricula() == matricula)
        {
            std::cout << "Salario do funcionario: " << it->calcularSalario() << " Reais.\n";
            return;
        }
    }
    std::cout<< "Funcionario com matricula " << matricula << "nao encontrado no sistema.\n";
}

void Empresa::calcularTodoOsSalarios() {

    std::ofstream arquivo("salarios.txt");

    if (arquivo.is_open()) {
        for(vector<Gerente>::iterator it{gerentes.begin()}; it != gerentes.end(); it++)
        {
            arquivo << "Funcionario: " << it->getNome() << "; Funçao: Gerente; Salario: "<< it->calcularSalario() << " Reais.\n";
        }
        for(vector<Vendedor>::iterator it{vendedores.begin()}; it != vendedores.end(); it++)
        {
            arquivo << "Funcionario: " << it->getNome() << "; Funçao: Vendedor; Salario: "<< it->calcularSalario() << " Reais.\n";
        }
        for(vector<Asg>::iterator it{asgs.begin()}; it != asgs.end(); it++)
        {
            arquivo << "Funcionario: " << it->getNome() << "; Funçao: ASG; Salario: "<< it->calcularSalario() << " Reais.\n";
        }
        arquivo.close();

    } else {
        std::cout << "Erro ao abrir o arquivo." << std::endl;
    }
}

void Empresa::calcularRecisaoFuncionario(std::string matricula, util::Data hoje) {
     for(vector<Gerente>::iterator it{gerentes.begin()}; it != gerentes.end(); it++)
    {
        if(it->getMatricula() == matricula)
        {
            std::cout << "Recisao do funcionario: " << it->calcularRecisao(hoje) << " Reais.\n";
            return;
        }
    }
    for(vector<Vendedor>::iterator it{vendedores.begin()}; it != vendedores.end(); it++)
    {
        if(it->getMatricula() == matricula)
        {
            std::cout << "Recisao do funcionario: " << it->calcularRecisao(hoje) << " Reais.\n";
            return;
        }
    }
    for(vector<Asg>::iterator it{asgs.begin()}; it != asgs.end(); it++)
    {
        if(it->getMatricula() == matricula)
        {
            std::cout << "Recisao do funcionario: " << it->calcularRecisao(hoje) << " Reais.\n";
            return;
        }
    }
    std::cout<< "Funcionario com matricula " << matricula << "nao encontrado.\n";
}

void Empresa::calcularRecisaoTodosFuncionarios(util::Data hoje) {
    std::ofstream arquivo("recisoes.txt");

    if (arquivo.is_open()) {
        for(vector<Gerente>::iterator it{gerentes.begin()}; it != gerentes.end(); it++)
        {
            arquivo << "Funcionario: " << it->getNome() << "; Funçao: Gerente; Recisao: "<< it->calcularRecisao(hoje) << " Reais.\n";
        }
        for(vector<Vendedor>::iterator it{vendedores.begin()}; it != vendedores.end(); it++)
        {
            arquivo << "Funcionario: " << it->getNome() << "; Funçao: Vendedor; Recisao: "<< it->calcularRecisao(hoje) << " Reais.\n";
        }
        for(vector<Asg>::iterator it{asgs.begin()}; it != asgs.end(); it++)
        {
            arquivo << "Funcionario: " << it->getNome() << "; Funçao: ASG; Recisao: "<< it->calcularRecisao(hoje) << " Reais.\n";
        }
        arquivo.close();
        
    } else {
        std::cout << "Erro ao abrir o arquivo." << std::endl;
    }
}

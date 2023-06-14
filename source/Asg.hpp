#ifndef ASG_HPP
#define ASG_HPP
#include <string>
#include "util.hpp"
#include "Pessoa.hpp"
#include "Funcionario.hpp"

//Definição da classe Asg
class Asg : public Pessoa, public Funcionario {
private:
    float adicionalInsalubridade;

public:
    Asg();

    Asg(std::string, std::string, Data, Endereco, std::string, int, float, std::string, Data, float);

    // Getters e Setters
    float getAdicionalInsalubridade() const;

    void setAdicionalInsalubridade(float);

    float calcularSalario(int) override;
    float calcularRecisao(Data) override;
};

#endif
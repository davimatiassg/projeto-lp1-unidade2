#include <string>
#include <sstream>
#include "util.hpp"

    
std::string util::formatarData(util::Data d)
{
    std::stringstream ss;
    ss << d.dia << "/" << d.mes << "/" << d.ano;
    return ss.str();
}

std::string util::formatarEndereco(util::Endereco e)
{
    std::stringstream ss;
    ss << e.rua << ", n: " << e.numero << ", bairro " << e.bairro << ", "<< e.cidade << ".";
    return ss.str();
}


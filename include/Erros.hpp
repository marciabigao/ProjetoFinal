#ifndef ERROS_H
#define ERROS_H

#include <exception>
#include <string>

class ExcecaoJogadorRepetido : public std::exception
{
    public:
    virtual const char* what() const throw()
    {
        return "ERRO: jogador repetido";
    }
};

class ExcecaoJogadorInexistente : public std::exception
{
    public:
    virtual const char* what() const throw()
    {
        return "ERRO: jogador inexistente";
    }
};

class ExcecaoMapVazio : public std::exception 
{
    public:
    virtual const char* what() const throw()
    {
        return "ERRO: ainda não existem jogadores cadastrados";
    }
};

class ExcecaoNaoExistemJogadasValidas : public std::exception
{
    private:
    std::string apelido;

    public:
    ExcecaoNaoExistemJogadasValidas(std::string apelido) : apelido(apelido) {}

    virtual const char* what() const throw()
    {
        std::string erro = "Não existem jogadas válidas para " + apelido;
        const char* texto = erro.c_str();
        return texto;
    }
};

#endif
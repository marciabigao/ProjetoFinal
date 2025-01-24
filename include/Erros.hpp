#ifndef ERROS_H
#define ERROS_H

#include <exception>
#include <string>

/*!
 * \class ExcecaoJogadorRepetido
 * \brief Exceção para indicar que o jogador já foi cadastrado.
 */
class ExcecaoJogadorRepetido : public std::exception
{
    public:
    /// Retorna a mensagem de erro para jogador repetido.
    virtual const char* what() const throw()
    {
        return "ERRO: jogador repetido";
    }
};

/*!
 * \class ExcecaoJogadorInexistente
 * \brief Exceção para indicar que o jogador não foi encontrado.
 */

class ExcecaoJogadorInexistente : public std::exception
{
    public:
    /// Retorna a mensagem de erro para jogador inexistente.
    virtual const char* what() const throw()
    {
        return "ERRO: jogador inexistente";
    }
};

/*!
 * \class ExcecaoMapVazio
 * \brief Exceção para indicar que não há jogadores cadastrados.
 */
class ExcecaoMapVazio : public std::exception 
{
    public:
    /// Retorna a mensagem de erro para lista de jogadores vazia.
    virtual const char* what() const throw()
    {
        return "ERRO: ainda não existem jogadores cadastrados";
    }
};
/*!
 * \class ExcecaoNaoExistemJogadasValidas
 * \brief Exceção para indicar que não existem jogadas válidas para o jogador.
 */
class ExcecaoNaoExistemJogadasValidas : public std::exception
{
    private:
    std::string apelido;///< Apelido do jogador associado à exceção.

    public:
    /// Construtor que recebe o apelido do jogador.
    ExcecaoNaoExistemJogadasValidas(std::string apelido) : apelido(apelido) {}
    /// Retorna a mensagem de erro com o apelido do jogador.
    virtual const char* what() const throw()
    {
        std::string erro = "Não existem jogadas válidas para " + apelido;
        const char* texto = erro.c_str();
        return texto;
    }
};

#endif
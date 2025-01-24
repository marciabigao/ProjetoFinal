#ifndef JOGOS_HPP
#define JOGOS_HPP

#include <iostream>
#include <vector>
#include "Jogador.hpp"

/*!
 * \class Jogos
 * \brief Classe base para a implementação de jogos baseados em tabuleiros.
 * 
 * Define a estrutura básica de um jogo, incluindo gerenciamento do tabuleiro,
 * controle do jogador atual e métodos virtuais para implementação em jogos específicos.
 */
class Jogos {
protected:
    std::vector<std::vector<char>> tabuleiro; /*!< Representa o tabuleiro do jogo como uma matriz de caracteres. */
    char jogadorAtual; /*!< Indica o jogador atual ('X' ou 'O'). */

public:
    /*!
     * \brief Construtor da classe Jogos.
     * \param linhas Número de linhas do tabuleiro.
     * \param colunas Número de colunas do tabuleiro.
     * \param jogadorAtual Jogador que inicia o jogo ('X' ou 'O').
     */
    Jogos(int linhas, int colunas, char jogadorAtual);

    /*!
     * \brief Destrutor virtual da classe Jogos.
     */
    virtual ~Jogos();

    /*!
     * \brief Retorna uma referência constante ao tabuleiro.
     * \return Referência para o tabuleiro representado como uma matriz de caracteres.
     */
    const std::vector<std::vector<char>> & getTabuleiro() const;

    /*!
     * \brief Define um novo estado para o tabuleiro.
     * \param novoTabuleiro Matriz de caracteres representando o novo tabuleiro.
     */
    void setTabuleiro(const std::vector<std::vector<char>> & novoTabuleiro);

    /*!
     * \brief Imprime o tabuleiro no console.
     */
    virtual void imprimirTabuleiro() const;

    /*!
     * \brief Reinicia o tabuleiro, preenchendo todas as células com espaços em branco.
     */
    void reiniciarTabuleiro();

    /*!
     * \brief Retorna o valor de uma célula específica do tabuleiro.
     * \param linha Índice da linha.
     * \param coluna Índice da coluna.
     * \return Caractere na célula especificada.
     * \throws std::invalid_argument Se a posição estiver fora dos limites do tabuleiro.
     */
    char getCelula(int linha, int coluna) const;

    /*!
     * \brief Define o valor de uma célula específica do tabuleiro.
     * \param linha Índice da linha.
     * \param coluna Índice da coluna.
     * \param valor Novo valor para a célula.
     * \throws std::invalid_argument Se a posição estiver fora dos limites do tabuleiro.
     */
    void setCelula(int linha, int coluna, char valor);

    /*!
     * \brief Verifica se uma jogada é válida.
     * \param linha Índice da linha.
     * \param coluna Índice da coluna.
     * \return `true` se a jogada for válida, `false` caso contrário.
     */
    virtual bool testarValidade(int linha, int coluna) = 0;

    /*!
     * \brief Verifica se o jogador atual venceu o jogo.
     * \return `true` se houver uma vitória, `false` caso contrário.
     */
    virtual bool testarVitoria() = 0;

    /*!
     * \brief Executa uma jogada no tabuleiro.
     * \param linha Índice da linha.
     * \param coluna Índice da coluna.
     */
    virtual void executarJogada(int linha, int coluna) = 0;

    /*!
     * \brief Alterna entre os jogadores ('X' e 'O').
     */
    virtual void alternarJogador() = 0;

    /*!
     * \brief Executa uma partida completa entre dois jogadores.
     * \param jogador1 Ponteiro para o primeiro jogador.
     * \param jogador2 Ponteiro para o segundo jogador.
     */
    virtual void executarPartida(Jogador* jogador1, Jogador* jogador2) = 0;
};

#endif

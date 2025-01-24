#ifndef LIG4_H
#define LIG4_H

#include "Jogos.hpp"
#include "Jogador.hpp"

/*!
 * \class Lig4
 * \brief Implementa o jogo Lig4, derivado da classe base Jogos.
 * 
 * A classe contém a lógica específica do jogo Lig4, como validação de jogadas, controle do jogador atual, e verificação de vitórias e empates.
 */
class Lig4 : public Jogos {

private:
    int _numLinhas; /*!< Número de linhas do tabuleiro. */
    int _numColunas; /*!< Número de colunas do tabuleiro. */

public:

    /*!
     * \brief Construtor que inicializa o jogo Lig4 com as dimensões do tabuleiro.
     * \param linhas Número de linhas do tabuleiro.
     * \param colunas Número de colunas do tabuleiro.
     */
    Lig4(int linhas, int colunas);

    /*!
     * \brief Destrutor da classe Lig4.
     */
    ~Lig4();

    /*!
     * \brief Retorna o número de linhas do tabuleiro.
     * \return Número de linhas.
     */
    int getNumLinhas();

    /*!
     * \brief Retorna o número de colunas do tabuleiro.
     * \return Número de colunas.
     */
    int getNumColunas();

    /*!
     * \brief Retorna o jogador atual ('X' ou 'O').
     * \return Caractere representando o jogador atual.
     */
    char getJogadorAtual();

    /*!
     * \brief Verifica se uma jogada em determinada posição é válida.
     * \param linha Índice da linha da jogada.
     * \param coluna Índice da coluna da jogada.
     * \return `true` se a jogada for válida, `false` caso contrário.
     */
    virtual bool testarValidade(int linha, int coluna) override;

    /*!
     * \brief Executa uma jogada no tabuleiro.
     * \param linha Índice da linha onde a jogada será realizada.
     * \param coluna Índice da coluna onde a jogada será realizada.
     */
    void executarJogada(int linha, int coluna) override;

    /*!
     * \brief Executa uma partida completa entre dois jogadores.
     * \param jogador1 Ponteiro para o primeiro jogador.
     * \param jogador2 Ponteiro para o segundo jogador.
     */
    void executarPartida(Jogador* jogador1, Jogador* jogador2);

    /*!
     * \brief Alterna entre os jogadores ('X' e 'O').
     */
    void alternarJogador() override;

    /*!
     * \brief Verifica se o jogador atual venceu a partida.
     * \return `true` se houver uma vitória, `false` caso contrário.
     */
    virtual bool testarVitoria() override;

    /*!
     * \brief Verifica se a partida terminou em empate.
     * \return `true` se todas as posições do tabuleiro estiverem preenchidas sem um vencedor.
     */
    bool testarEmpate() const;

};

#endif

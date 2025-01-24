#ifndef JOGO_DA_VELHA_HPP
#define JOGO_DA_VELHA_HPP

#include "Jogos.hpp"
#include "Jogador.hpp"
#include <iostream>

/*!
 * \class JogoDaVelha
 * \brief Representa o jogo da velha, derivado da classe base Jogos.
 * 
 * Implementa as regras específicas do jogo da velha, como validação de jogadas,
 * verificação de vitória, empate e controle de turnos entre os jogadores.
 */
class JogoDaVelha : public Jogos { 

    public:

    /*!
     * \brief Construtor padrão que inicializa o jogo da velha.
     */
    JogoDaVelha();

    /*!
     * \brief Destrutor da classe JogoDaVelha.
     */
    ~JogoDaVelha();

    /*!
     * \brief Verifica se a jogada em uma posição do tabuleiro é válida.
     * \param linha Índice da linha no tabuleiro.
     * \param coluna Índice da coluna no tabuleiro.
     * \return `true` se a posição estiver vazia, `false` caso contrário.
     */
    bool testarValidade(int linha, int coluna) override;

    /*!
     * \brief Verifica se o jogador atual venceu a partida.
     * \return `true` se o jogador atual fez uma sequência vencedora, `false` caso contrário.
     */
    bool testarVitoria() override;

    /*!
     * \brief Executa uma partida completa entre dois jogadores.
     * \param jogador1 Ponteiro para o primeiro jogador.
     * \param jogador2 Ponteiro para o segundo jogador.
     */
    void executarPartida(Jogador* jogador1, Jogador* jogador2) override;

    /*!
     * \brief Alterna o jogador atual entre 'X' e 'O'.
     */
    void alternarJogador() override;

    /*!
     * \brief Realiza uma jogada no tabuleiro para o jogador atual.
     * \param linha Índice da linha onde será realizada a jogada.
     * \param coluna Índice da coluna onde será realizada a jogada.
     */
    void executarJogada(int linha, int coluna) override;

    /*!
     * \brief Verifica se a partida terminou em empate.
     * \return `true` se todas as posições do tabuleiro estiverem preenchidas sem um vencedor.
     */
    bool testarEmpate();  

};

#endif // JOGO_DA_VELHA_HPP

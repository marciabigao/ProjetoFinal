#ifndef REVERSI_HPP
#define REVERSI_HPP

#include "Jogos.hpp"

/*!
 * \class Reversi
 * \brief Implementa o jogo Reversi (ou Othello), derivado da classe base Jogos.
 * 
 * A classe contém a lógica específica do jogo Reversi, incluindo validação de jogadas,
 * alternância de jogadores, inversão de símbolos e declaração de vencedor.
 */
class Reversi : public Jogos {
    public:

    /*!
     * \brief Construtor padrão da classe Reversi.
     * 
     * Inicializa o tabuleiro e o jogador inicial.
     */
    Reversi();

    /*!
     * \brief Destrutor da classe Reversi.
     */
    ~Reversi();

    /*!
     * \brief Verifica se uma jogada em determinada posição é válida.
     * \param linha Índice da linha da jogada.
     * \param coluna Índice da coluna da jogada.
     * \return `true` se a jogada for válida, `false` caso contrário.
     */
    bool testarValidade(int linha, int coluna) override;

    /*!
     * \brief Verifica se o jogador atual venceu a partida.
     * \return `true` se o jogador atual vencer, `false` caso contrário.
     */
    bool testarVitoria() override;

    /*!
     * \brief Executa uma partida completa entre dois jogadores.
     * \param jogador1 Ponteiro para o primeiro jogador.
     * \param jogador2 Ponteiro para o segundo jogador.
     */
    void executarPartida(Jogador* jogador1, Jogador* jogador2) override;

    /*!
     * \brief Alterna entre os jogadores ('X' e 'O').
     */
    void alternarJogador() override;

    /*!
     * \brief Realiza uma jogada no tabuleiro.
     * \param linha Índice da linha onde a jogada será realizada.
     * \param coluna Índice da coluna onde a jogada será realizada.
     */
    void executarJogada(int linha, int coluna) override;

    /*!
     * \brief Declara o vencedor da partida com base no número de peças de cada jogador.
     * \return Caractere representando o vencedor ('X', 'O') ou 'E' em caso de empate.
     */
    char declararVencedor();

    /*!
     * \brief Inverte os símbolos do tabuleiro após uma jogada válida.
     * \param linha Índice da linha da jogada.
     * \param coluna Índice da coluna da jogada.
     */
    void inverterSimbolos(int linha, int coluna);

    /*!
     * \brief Verifica se ainda existem jogadas válidas disponíveis para o jogador atual.
     * \return `true` se houver jogadas válidas, `false` caso contrário.
     */
    bool existemJogadasValidas();
};

#endif

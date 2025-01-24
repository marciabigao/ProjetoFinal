/*!
 * \file testes_Reversi.cpp
 * \brief Arquivo de testes unitários para a classe `Reversi` utilizando a biblioteca Doctest.
 * 
 * Este arquivo contém os testes para verificar o comportamento correto da classe `Reversi`,
 * incluindo validações de jogadas, alternância de jogadores, vitórias e a execução de jogadas.
 */

#include "doctest.h"
#include "Reversi.hpp"

/*!
 * \brief Testa os métodos `alternarJogador` e `executarJogada` da classe `Reversi`.
 * 
 * Verifica se:
 * - O jogador alterna corretamente entre 'X' e 'O'.
 * - A jogada é registrada corretamente no tabuleiro.
 */
TEST_CASE("Testando o método para alternar jogador e para executar jogada") {
    Reversi teste;

    teste.executarJogada(3, 5);
    CHECK(teste.getCelula(3, 5) == 'X'); /*!< Verifica se a jogada foi registrada. */
    teste.alternarJogador();
    teste.executarJogada(6, 5);
    CHECK(teste.getCelula(6, 5) == 'O'); /*!< Verifica se o jogador alternado registrou a jogada. */
}

/*!
 * \brief Testa o método `testarValidade` da classe `Reversi`.
 * 
 * Verifica se posições válidas e inválidas para jogadas são corretamente detectadas.
 */
TEST_CASE("Testando método de validação") {
    Reversi teste;

    CHECK(teste.testarValidade(2, 4)); /*!< Posição válida. */
    CHECK(teste.testarValidade(3, 5)); /*!< Posição válida. */
    CHECK(teste.testarValidade(4, 2)); /*!< Posição válida. */
    CHECK(teste.testarValidade(5, 3)); /*!< Posição válida. */

    CHECK(!teste.testarValidade(2, 2)); /*!< Posição inválida. */
    CHECK(!teste.testarValidade(3, 2)); /*!< Posição inválida. */
    CHECK(!teste.testarValidade(5, 2)); /*!< Posição inválida. */
    CHECK(!teste.testarValidade(5, 4)); /*!< Posição inválida. */
}

/*!
 * \brief Testa o método `testarVitoria` da classe `Reversi`.
 * 
 * Simula condições de jogo para verificar quando o jogo detecta uma vitória.
 */
TEST_CASE("Testando método de vitória") {
    Reversi teste;

    // Preenchendo o tabuleiro e verificando ausência de vitória
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 7; j++) {
            if (!((i == 4 && j == 3) || (i == 3 && j == 4))) {
                teste.executarJogada(i, j);
            }
            CHECK(!teste.testarVitoria()); /*!< Verifica que ainda não há vitória. */
        }
    }

    // Preenchendo a última coluna para criar uma vitória
    for (int i = 0; i < 7; i++) {
        CHECK(!teste.testarVitoria()); /*!< Verifica que ainda não há vitória. */
        teste.executarJogada(i, 7);
    }

    teste.executarJogada(7, 7);
    CHECK(teste.testarVitoria()); /*!< Verifica que há vitória ao completar o tabuleiro. */
}

/*!
 * \brief Testa o método `executarJogada` da classe `Reversi`.
 * 
 * Verifica se as jogadas são registradas corretamente no tabuleiro para todas as posições.
 */
TEST_CASE("Testando método de executar jogada") {
    Reversi teste;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            teste.executarJogada(i, j);
            CHECK(teste.getCelula(i, j)); /*!< Verifica se a jogada foi registrada. */
        }
    }
}

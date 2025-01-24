/*!
 * \file testes_JogoDaVelha.cpp
 * \brief Arquivo de testes unitários para a classe `JogoDaVelha` utilizando a biblioteca Doctest.
 * 
 * Este arquivo contém os testes para verificar o comportamento correto da classe `JogoDaVelha`.
 * Os testes incluem validações para inicialização, verificação de jogadas válidas, vitórias e empates.
 */

#include "doctest.h"
#include "../include/JogodaVelha.hpp"

/*!
 * \brief Testa a inicialização do jogo da velha.
 * 
 * Verifica se um jogo recém-inicializado não possui empate.
 */
TEST_CASE("Testando Inicialização do Jogo") {
    JogoDaVelha jogo;
    CHECK(jogo.testarEmpate() == false); /*!< Verifica que o jogo não está empatado inicialmente. */
}

/*!
 * \brief Testa o método `testarValidade` da classe `JogoDaVelha`.
 * 
 * Verifica se posições vazias são consideradas válidas e se posições ocupadas não são válidas para jogadas.
 */
TEST_CASE("Testando testarValidade") {
    JogoDaVelha jogo;
    CHECK(jogo.testarValidade(0, 0) == true); /*!< Posição vazia deve ser válida. */
    jogo.executarJogada(0, 0); /*!< Executa jogada na posição (0, 0). */
    CHECK(jogo.testarValidade(0, 0) == false); /*!< Posição ocupada não deve ser válida. */
}

/*!
 * \brief Testa o método `testarVitoria` da classe `JogoDaVelha`.
 * 
 * Verifica diferentes condições de vitória:
 * - Vitória na mesma linha.
 * - Vitória na mesma coluna.
 * - Vitória na diagonal.
 */
TEST_CASE("Testando testarVitoria") {
    JogoDaVelha jogo;

    // Vitória na mesma linha
    jogo.executarJogada(0, 0); // "X"
    jogo.executarJogada(1, 0); // "O"
    jogo.executarJogada(0, 1); // "X"
    jogo.executarJogada(1, 1); // "O"
    jogo.executarJogada(0, 2); // "X"
    CHECK(jogo.testarVitoria() == true); /*!< X deve vencer na linha 0. */

    // Vitória na mesma coluna
    jogo = JogoDaVelha(); /*!< Reinicia o jogo. */
    jogo.executarJogada(0, 0); // "X"
    jogo.executarJogada(0, 1); // "O"
    jogo.executarJogada(1, 0); // "X"
    jogo.executarJogada(1, 1); // "O"
    jogo.executarJogada(2, 0); // "X"
    CHECK(jogo.testarVitoria() == true); /*!< X deve vencer na coluna 0. */

    // Vitória na diagonal
    jogo = JogoDaVelha(); /*!< Reinicia o jogo. */
    jogo.executarJogada(0, 0); // "X"
    jogo.executarJogada(0, 1); // "O"
    jogo.executarJogada(1, 1); // "X"
    jogo.executarJogada(1, 0); // "O"
    jogo.executarJogada(2, 2); // "X"
    CHECK(jogo.testarVitoria() == true); /*!< X deve vencer na diagonal. */
}

/*!
 * \brief Testa o método `testarEmpate` da classe `JogoDaVelha`.
 * 
 * Simula um jogo completo que resulta em empate e verifica se a condição é detectada corretamente.
 */
TEST_CASE("Testando testarEmpate") {
    JogoDaVelha jogo;

    // Simula um jogo empatado
    jogo.executarJogada(0, 0); // "X"
    jogo.executarJogada(0, 1); // "O"
    jogo.executarJogada(0, 2); // "X"
    jogo.executarJogada(1, 0); // "O"
    jogo.executarJogada(1, 2); // "X"
    jogo.executarJogada(1, 1); // "O"
    jogo.executarJogada(2, 0); // "X"
    jogo.executarJogada(2, 2); // "O"
    jogo.executarJogada(2, 1); // "X"
    CHECK(jogo.testarEmpate() == true); /*!< O jogo deve estar empatado. */
}

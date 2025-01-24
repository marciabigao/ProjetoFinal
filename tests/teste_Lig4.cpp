/*!
 * \file testes_Lig4.cpp
 * \brief Arquivo de testes unitários para a classe `Lig4` utilizando a biblioteca Doctest.
 * 
 * Este arquivo contém testes para verificar o comportamento correto da classe `Lig4`,
 * incluindo validações de inicialização, alternância de jogadores, jogadas, vitórias e empates.
 */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Lig4.hpp"

/*!
 * \brief Testa a inicialização do construtor e os getters da classe `Lig4`.
 * 
 * Verifica se as dimensões do tabuleiro e o jogador inicial são configurados corretamente.
 */
TEST_CASE("Testando Construtor e Getters") {
    Lig4 teste(6, 7);

    CHECK(teste.getNumLinhas() == 6); /*!< Verifica se o número de linhas é 6. */
    CHECK(teste.getNumColunas() == 7); /*!< Verifica se o número de colunas é 7. */
    CHECK(teste.getJogadorAtual() == 'A'); /*!< Verifica se o jogador inicial é 'A' (Amarelo). */
}

/*!
 * \brief Testa o método `testarValidade` da classe `Lig4`.
 * 
 * Verifica se as posições no tabuleiro são validadas corretamente.
 * Testa também exceções para entradas inválidas.
 */
TEST_CASE("Testando método de validação") {
    Lig4 teste(6, 7);

    for (int i = 0; i < 7; i++) {
        CHECK(teste.testarValidade(-1, i)); /*!< Posições válidas nas colunas. */
    }

    CHECK_THROWS_AS(teste.testarValidade(-1, -1), std::invalid_argument); /*!< Entrada fora do tabuleiro. */
    CHECK_THROWS_AS(teste.testarValidade(-1, 7), std::invalid_argument); /*!< Entrada fora do tabuleiro. */

    for (int i = 0; i < 6; i++) {
        teste.setCelula(i, 2, 'X'); /*!< Preenche a coluna 2. */
    }

    CHECK(!teste.testarValidade(0, 2)); /*!< Verifica que a coluna cheia não é válida. */
}

/*!
 * \brief Testa o método `executarJogada` da classe `Lig4`.
 * 
 * Verifica se as jogadas são realizadas corretamente no tabuleiro.
 */
TEST_CASE("Testando método de execução da jogada") {
    Lig4 teste(6, 7);

    for (int i = 5; i >= 0; i--) {
        for (int j = 0; j < 7; j++) {
            teste.executarJogada(-1, j);
            CHECK(teste.getCelula(i, j) == teste.getJogadorAtual()); /*!< Verifica se a jogada foi registrada. */
        }
    }
}

/*!
 * \brief Testa o método `alternarJogador` da classe `Lig4`.
 * 
 * Verifica se o jogador atual alterna corretamente entre 'A' (Amarelo) e 'V' (Vermelho).
 */
TEST_CASE("Testando o método para alternar jogador") {
    Lig4 teste(6, 7);

    teste.alternarJogador();
    CHECK(teste.getJogadorAtual() == 'V'); /*!< Jogador alterna para Vermelho. */
    teste.alternarJogador();
    CHECK(teste.getJogadorAtual() == 'A'); /*!< Jogador alterna para Amarelo. */
}

/*!
 * \brief Testa o método `testarVitoria` da classe `Lig4`.
 * 
 * Verifica diferentes condições de vitória:
 * - Linhas horizontais.
 * - Colunas verticais.
 * - Diagonais.
 */
TEST_CASE("Testando o Método para Vitoria") {
    Lig4 teste(6, 7);

    CHECK(!teste.testarVitoria()); /*!< Sem vitória no início. */

    for (int i = 2; i < 6; i++) {
        teste.executarJogada(-1, i); /*!< Vitória horizontal. */
    }
    CHECK(teste.testarVitoria());

    teste.reiniciarTabuleiro();

    for (int i = 0; i < 4; i++) {
        teste.executarJogada(-1, 3); /*!< Vitória vertical. */
    }
    CHECK(teste.testarVitoria());

    teste.reiniciarTabuleiro();

    for (int i = 2; i < 6; i++) {
        teste.setCelula(i, i, teste.getJogadorAtual()); /*!< Vitória diagonal. */
    }
    CHECK(teste.testarVitoria());
}

/*!
 * \brief Testa o método `testarEmpate` da classe `Lig4`.
 * 
 * Simula um tabuleiro completo e verifica se a condição de empate é detectada corretamente.
 */
TEST_CASE("Testando o Método para empate") {
    Lig4 teste(6, 7);

    CHECK(!teste.testarEmpate()); /*!< Sem empate no início. */

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            teste.executarJogada(-1, j);
            if (i != 5 && j != 6) {
                CHECK(!teste.testarEmpate()); /*!< Sem empate antes do tabuleiro completo. */
            }
        }
    }

    CHECK(teste.testarEmpate()); /*!< Tabuleiro completo deve resultar em empate. */
}

/*!
 * \brief Testa o método `testarVitoria` da classe `Lig4` para múltiplas condições.
 * 
 * Verifica vitórias horizontais, verticais e diagonais com cenários simulados.
 */
TEST_CASE("Testando o Método para vitoria") {
    Lig4 teste(6, 7);

    for (int i = 2; i < 5; i++) {
        teste.executarJogada(0, i); /*!< Teste de vitória horizontal. */
        CHECK(!teste.testarVitoria());
    }
    teste.executarJogada(0, 5);
    CHECK(teste.testarVitoria());

    teste.reiniciarTabuleiro();

    for (int i = 0; i < 3; i++) {
        teste.executarJogada(i, 3); /*!< Teste de vitória vertical. */
        CHECK(!teste.testarVitoria());
    }
    teste.executarJogada(0, 3);
    CHECK(teste.testarVitoria());

    teste.reiniciarTabuleiro();

    try {
        for (int i = 2; i < 5; i++) {
            teste.setCelula(i, i, teste.getJogadorAtual()); /*!< Teste de vitória diagonal. */
            CHECK(!teste.testarVitoria());
        }
        teste.setCelula(5, 5, teste.getJogadorAtual());
        CHECK(teste.testarVitoria());
    } catch (std::invalid_argument& e) {
        throw;
    }
}

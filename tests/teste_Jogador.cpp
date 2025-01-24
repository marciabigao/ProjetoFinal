/*!
 * \file testes.cpp
 * \brief Arquivo de testes unitários utilizando a biblioteca Doctest.
 * 
 * Este arquivo contém os testes para verificar o comportamento correto da classe `Jogador`.
 * Os testes incluem validações para o construtor, registro de vitórias e derrotas.
 */

#include "doctest.h"
#include "Jogador.hpp"

/*!
 * \brief Testa a inicialização do construtor da classe `Jogador`.
 * 
 * Verifica se os atributos do objeto são inicializados corretamente com os valores fornecidos.
 */
TEST_CASE("Inicialização do Construtor") {
    Jogador jogador("Paulo", "paulin123", 1, 2, 3, 4, 5, 6);

    CHECK(jogador.getNome() == "Paulo");
    CHECK(jogador.getApelido() == "paulin123");
    CHECK(jogador.getVitoriasR() == 1);
    CHECK(jogador.getDerrotasR() == 2);
    CHECK(jogador.getVitoriasLig() == 3);
    CHECK(jogador.getDerrotasLig() == 4);
    CHECK(jogador.getVitoriasJV() == 5);
    CHECK(jogador.getDerrotasJV() == 6);
}

/*!
 * \brief Testa o método `registrarVitoria` da classe `Jogador`.
 * 
 * Verifica se o registro de vitórias funciona corretamente para diferentes jogos:
 * - Reversi ('R')
 * - Lig4 ('L')
 * - Jogo da Velha ('V')
 */
TEST_CASE("Testando registrarVitoria") {
    Jogador jogador("Marcia", "bigadas");
    jogador.cadastraJogador("bigadas");

    jogador.registrarVitoria('R');
    jogador.registrarVitoria('L');
    jogador.registrarVitoria('V');

    CHECK(jogador.getVitoriasR() == 1);
    CHECK(jogador.getVitoriasLig() == 1);
    CHECK(jogador.getVitoriasJV() == 1);
}

/*!
 * \brief Testa o método `registrarDerrota` da classe `Jogador`.
 * 
 * Verifica se o registro de derrotas funciona corretamente para diferentes jogos:
 * - Reversi ('R')
 * - Lig4 ('L')
 * - Jogo da Velha ('V')
 */
TEST_CASE("Testando registrarDerrota") {
    Jogador jogador("Vitor", "vitinfaleiro");
    jogador.cadastraJogador("vitinfaleiro");

    jogador.registrarDerrota('R');
    jogador.registrarDerrota('L');
    jogador.registrarDerrota('V');

    CHECK(jogador.getDerrotasR() == 1);
    CHECK(jogador.getDerrotasLig() == 1);
    CHECK(jogador.getDerrotasJV() == 1);
}

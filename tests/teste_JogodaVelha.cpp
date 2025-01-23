#include "doctest.h"
#include "../include/JogodaVelha.hpp"

TEST_CASE("Testando Inicialização do Jogo"){
    JogoDaVelha jogo;
    CHECK(jogo.testarEmpate() == false); 
}

TEST_CASE("Testando testarValidade"){
    JogoDaVelha jogo;
    CHECK(jogo.testarValidade(0, 0) == true); // Posição vazia
    jogo.executarJogada(0, 0); // Posição agora vai ter um "X"
    CHECK(jogo.testarValidade(0, 0) == false); // Posição ocupada com o X
}

TEST_CASE("Testando testarVitoria"){
    JogoDaVelha jogo;

    // Vitória na mesma linha
    jogo.executarJogada(0, 0); // "X"
    jogo.executarJogada(1, 0); // "O"
    jogo.executarJogada(0, 1); // "X"
    jogo.executarJogada(1, 1); // "O"
    jogo.executarJogada(0, 2); // "X"
    CHECK(jogo.testarVitoria() == true); // X deve vencer na linha 0

    // Vitória na mesma coluna
    jogo = JogoDaVelha();
    jogo.executarJogada(0, 0); // "X"
    jogo.executarJogada(0, 1); // "O"
    jogo.executarJogada(1, 0); // "X"
    jogo.executarJogada(1, 1); // "O"
    jogo.executarJogada(2, 0); // "X"
    CHECK(jogo.testarVitoria() == true); // X deve vencer na coluna 0

    // Vitória na diagonal
    jogo = JogoDaVelha();
    jogo.executarJogada(0, 0); // "X"
    jogo.executarJogada(0, 1); // "O"
    jogo.executarJogada(1, 1); // "X"
    jogo.executarJogada(1, 0); // "O"
    jogo.executarJogada(2, 2); // "X"
    CHECK(jogo.testarVitoria() == true); // X deve vencer na diagonal 

} 

TEST_CASE("Testando testarEmpate"){
    JogoDaVelha jogo;
 
    jogo.executarJogada(0, 0); // "X"
    jogo.executarJogada(0, 1); // "O"
    jogo.executarJogada(0, 2); // "X"
    jogo.executarJogada(1, 0); // "O"
    jogo.executarJogada(1, 2); // "X"
    jogo.executarJogada(1, 1); // "O"
    jogo.executarJogada(2, 0); // "X"
    jogo.executarJogada(2, 2); // "O"
    jogo.executarJogada(2, 1); // "X"
    CHECK(jogo.testarEmpate() == true); // Jogo deve estar empatado
}
 
// Não consegui testar o alternarJogador ainda

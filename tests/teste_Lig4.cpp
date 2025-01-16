#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Lig4.hpp"


TEST_CASE("Testando Construtor e Getters"){
    
    Lig4 teste(6,7);

    CHECK(teste.getNumLinhas() == 6);
    CHECK(teste.getNumColunas() == 7);
    CHECK(teste.getJogadorAtual() == 'A');
}

//Testar Destrutor

TEST_CASE("Testando método de validação"){

    Lig4 teste(6,7);

    for(int i = 0; i< 7; i++)
        CHECK(teste.testarValidade(-1,i));

    CHECK(!teste.testarValidade(-1,-1));
    CHECK(!teste.testarValidade(-1,7));

    for(int i = 0; i< 6; i++)
        teste.setCelula(i,2,'X');

    CHECK(!teste.testarValidade(0,2));
}

TEST_CASE("Testando método de execução da jogada"){

    Lig4 teste(6,7);

    for(int i = 5; i >= 0; i--){
        for(int j= 0; j< 7; j++){
            teste.executarJogada(-1,j);
            CHECK(teste.getCelula(i,j) == teste.getJogadorAtual());
        }
    }
}

TEST_CASE("Testando o método para alternar jogador"){

    Lig4 teste(6,7);

    teste.alternarJogador();
    CHECK(teste.getJogadorAtual() == 'V');
    teste.alternarJogador();
    CHECK(teste.getJogadorAtual() == 'A');
}

TEST_CASE("Testando o Método para Vitoria"){

    Lig4 teste(6,7);

    CHECK(!teste.testarVitoria());

    for(int i = 2; i < 6; i++)
        teste.executarJogada(-1,i);

    CHECK(teste.testarVitoria());

    teste.reiniciarTabuleiro();

    for(int i = 0; i < 4; i++)
        teste.executarJogada(-1,3);
    
    CHECK(teste.testarVitoria());

    for(int i = 2; i < 6; i++)
        teste.setCelula(i,i,teste.getJogadorAtual());

    CHECK(teste.testarVitoria());
}

TEST_CASE("Testando o Método para empate"){

    Lig4 teste(6,7);
    
    CHECK(!teste.testarEmpate());

    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 7; j++){
            teste.executarJogada(-1,j);
            if(i != 5 && j != 6)
                CHECK(!teste.testarEmpate());
        }
    }

    CHECK(teste.testarEmpate());
}
#include "doctest.h"
#include "Reversi.hpp"


TEST_CASE("Testando o método para alternar jogador e para executar jogada"){

    Reversi teste;

    teste.executarJogada(3,5);
    CHECK(teste.getCelula(3,5) == 'X');
    teste.alternarJogador();
    teste.executarJogada(6,5);
    CHECK(teste.getCelula(6,5) == 'O');
}


TEST_CASE("Testando método de validação"){

    Reversi teste; 

    CHECK(teste.testarValidade(2,4));
    CHECK(teste.testarValidade(3,5));
    CHECK(teste.testarValidade(4,2));
    CHECK(teste.testarValidade(5,3));

    CHECK(!teste.testarValidade(2,2));
    CHECK(!teste.testarValidade(3,2));
    CHECK(!teste.testarValidade(5,2));
    CHECK(!teste.testarValidade(5,4));
}

TEST_CASE("Testando método de vitória"){

    Reversi teste;

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 7; j++){
            if(!((i == 4 && j == 3) || (i == 3 && j == 4)))
                teste.executarJogada(i,j);
            CHECK(!teste.testarVitoria());
        }
    }

    for(int i = 0; i < 7; i++){
        CHECK(!teste.testarVitoria());
        teste.executarJogada(i,7);
    }

    teste.executarJogada(7,7);

    CHECK(teste.testarVitoria());

}

TEST_CASE("Testando método de executar jogada"){

    Reversi teste;

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){

            teste.executarJogada(i,j);
            CHECK(teste.getCelula(i,j));
        }
    }
}
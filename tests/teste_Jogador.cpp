#include "doctest.h"
#include "Jogador.hpp"

TEST_CASE("Inicialização do Construtor"){
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


TEST_CASE("Testando cadastrar, buscar e remover jogador"){
    Jogador* jogador1 = new Jogador("Lara", "larinha123");
    Jogador* jogador2 = new Jogador("Vitor", "vitinfaleiro");

    jogador1->cadastraJogador("larinha123");
    jogador2->cadastraJogador("vitinfaleiro");

    Jogador* encontrado = Jogador::buscaJogador("larinha123");
    CHECK(encontrado != nullptr);
    CHECK(encontrado->getNome() == "Lara");

    Jogador* naoEncontrado = Jogador::buscaJogador("naoExistente");
    CHECK(naoEncontrado == nullptr);

    jogador1->removeJogador("larinha123");
    encontrado = Jogador::buscaJogador("larinha123");
    CHECK(encontrado == nullptr);

    Jogador::apagaMap();
}
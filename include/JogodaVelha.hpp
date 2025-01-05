#ifndef JOGO_DA_VELHA_HPP
#define JOGO_DA_VELHA_HPP

#include "Jogos.hpp"
#include "Jogador.hpp"
#include <iostream>

class JogoDaVelha : public Jogos {

private:
    //define o símbolo do jogador atual (X ou O)
    char jogadorAtual; 


public:

    JogoDaVelha(); //construtor
    ~JogoDaVelha(); //destrutor

    //reescrita de métodos já existentes
    bool testarValidade(int linha, int coluna, char valor) override; 
    bool testarVitoria() override;
    void imprimirTabuleiro() const override;

    //métodos novos
    bool testarEmpate(); 
    void alternarJogador(); 
    void executarJogada(int linha, int coluna); 
    void executarJogo(Jogador& jogador1, Jogador& jogador2);
    
};

#endif // JOGO_DA_VELHA_HPP

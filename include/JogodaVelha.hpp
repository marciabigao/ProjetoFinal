#ifndef JOGO_DA_VELHA_HPP
#define JOGO_DA_VELHA_HPP

#include "Jogos.hpp"
#include "Jogador.hpp"
#include <iostream>

class JogoDaVelha : public Jogos { 

    public:

    JogoDaVelha(); //construtor
    ~JogoDaVelha(); //destrutor

    //reescrita de métodos já existentes
    bool testarValidade(int linha, int coluna) override; 
    bool testarVitoria() override;
    void executarPartida(Jogador* jogador1, Jogador* jogador2) override;
    void alternarJogador() override; 
    void executarJogada(int linha, int coluna) override;

    //métodos novos
    bool testarEmpate();  
    
};

#endif // JOGO_DA_VELHA_HPP

#ifndef REVERSI_HPP
#define REVERSI_HPP

#include "Jogos.hpp"

class Reversi : public Jogos {
    public:

    //Contrutor e Destrutor
    Reversi();
    ~Reversi();

    //Redefinição métodos virtuais
    bool testarValidade (int linha, int coluna) override;
    bool testarVitoria() override;
    void executarPartida(Jogador* jogador1, Jogador* jogador2) override;
    void alternarJogador() override;
    void executarJogada(int linha, int coluna) override;

    //Métodos exclusivos
    char declararVencedor();
    void inverterSimbolos(int linha, int coluna);
    bool existemJogadasValidas();
};

#endif
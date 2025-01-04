#ifndef REVERSI_HPP
#define REVERSI_HPP

#include "Jogos.hpp"

class Reversi : public Jogos {
    public:

    //Contrutor e Destrutor
    Reversi();
    ~Reversi();

    //Redefinição métodos virtuais
    bool testarValidade (int linha, int coluna, char valor) override;
    bool testarVitoria() override;

    //Métodos exclusivos
    char declararVencedor();
    void inverterSimbolos(int linha, int coluna);
};

#endif
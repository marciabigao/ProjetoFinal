#ifndef REVERSI_HPP
#define REVERSI_HPP

#include "Jogos.hpp"

class Reversi : public Jogos {
    private:
    int numeroPecasX;
    int numeroPecasO;
    int espacosDisponiveisTabuleiro;

    public:

    //Contrutor e Destrutor
    Reversi();
    ~Reversi();
};

#endif
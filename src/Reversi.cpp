#include "../include/Reversi.hpp"
#include <algorithm>

Reversi::Reversi() : Jogos(8, 8) {
    this->numeroPecasX = 32;
    this->numeroPecasO = 32;
    this->espacosDisponiveisTabuleiro = 64;
}

Reversi::~Reversi() {}
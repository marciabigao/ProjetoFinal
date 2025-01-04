#include "../include/Reversi.hpp"
#include <algorithm>

Reversi::Reversi() : Jogos(8, 8) {
    this->numeroPecasX = 32;
    this->numeroPecasO = 32;
    this->espacosDisponiveisTabuleiro = 64;
}

Reversi::~Reversi() {}

bool Jogos::testarValidade(int linha, int coluna) {
    bool validade = true;

    if(this->tabuleiro[linha][coluna] != ' ')
    {
        validade = false;
    }

    for(int i = 1; i <= 8; i++)
    {
        if(i != coluna && this->tabuleiro[linha][coluna] == this->tabuleiro[linha][i])
        {
            int pecasOpostas = 0;

            for(int j = std::min(i, coluna); j < std::max(i, coluna); j++)
            {
                if(this->tabuleiro[linha][j] == ' ')
                {
                    validade = false;
                }

                if(this->tabuleiro[linha][j] != ' ' && this->tabuleiro[linha][j] != this->tabuleiro[linha][coluna])
                {
                    pecasOpostas++;
                }
            }

            if(pecasOpostas == 0)
            {
                validade = false;
            }
        }
    }

    for(int i = 1; i <= 8; i++)
    {
        if(i != linha && this->tabuleiro[linha][coluna] == this->tabuleiro[i][coluna])
        {
            int pecasOpostas = 0;
            
            for(int j = std::min(i, linha); j < std::max(i, linha); j++)
            {
                if(this->tabuleiro[j][coluna] == ' ')
                {
                    validade = false;
                }

                if(this->tabuleiro[j][coluna] != ' ' && this->tabuleiro[j][coluna] != this->tabuleiro[linha][coluna])
                {
                    pecasOpostas++;
                }
            }

            if(pecasOpostas == 0)
            {
                validade = false;
            }
        }
    }

    return validade;
}
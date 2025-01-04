#include "../include/Reversi.hpp"
#include <algorithm>

Reversi::Reversi() : Jogos(8, 8) {}

Reversi::~Reversi() {}

bool Reversi::testarValidade(int linha, int coluna, char valor) {
    bool validade = true;

    if(this->tabuleiro[linha][coluna] != ' ')
    {
        validade = false;
    }

    for(int i = 0; i < 8; i++)
    {
        if(i != coluna && valor == this->tabuleiro[linha][i])
        {
            int pecasOpostas = 0;

            for(int j = std::min(i, coluna); j < std::max(i, coluna); j++)
            {
                if(this->tabuleiro[linha][j] == ' ')
                {
                    validade = false;
                }

                if(this->tabuleiro[linha][j] != ' ' && this->tabuleiro[linha][j] != valor)
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

    for(int i = 0; i < 8; i++)
    {
        if(i != linha && valor == this->tabuleiro[i][coluna])
        {
            int pecasOpostas = 0;
            
            for(int j = std::min(i, linha); j < std::max(i, linha); j++)
            {
                if(this->tabuleiro[j][coluna] == ' ')
                {
                    validade = false;
                }

                if(this->tabuleiro[j][coluna] != ' ' && this->tabuleiro[j][coluna] != valor)
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

bool Reversi::testarVitoria() {
    bool vitoria = true;

    for(int linha = 0; linha < 8; linha++)
    {
        for(int coluna = 0; coluna < 8; coluna++)
        {
            if(this->testarValidade(linha, coluna, 'X'))
            {
                vitoria = false;
            }
            
            if(this->testarValidade(linha, coluna, 'O'))
            {
                vitoria = false;
            }
        }
    }

    return vitoria;
}

void Reversi::lerJogada(int linha, int coluna) {

}
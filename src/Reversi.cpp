#include "../include/Reversi.hpp"
#include <algorithm>

Reversi::Reversi() : Jogos(8, 8) {}

Reversi::~Reversi() {}

bool Reversi::testarValidade(int linha, int coluna, char valor) {
    bool validadeGlobal;

    for(int i = 0; i < 8; i++)
    {
        if(i != coluna && valor == this->tabuleiro[linha][i])
        {
            bool validade = true;
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

            validadeGlobal = validadeGlobal || validade;
        }
    }

    for(int i = 0; i < 8; i++)
    {
        if(i != linha && valor == this->tabuleiro[i][coluna])
        {
            bool validade = true;
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

            validadeGlobal = validadeGlobal || validade;
        }
    }

    int i = linha;
    int j = coluna;
    do
    {
        i--;
        j++;

        if(this->tabuleiro[i][j] == valor)
        {
            bool validade = true;
            int pecasOpostas = 0;

            int a = linha - 1;
            int b = coluna + 1;

            do
            {
                if(this->tabuleiro[a][b] == ' ')
                {
                    validade = false;
                }
                if(this->tabuleiro[a][b] != ' ' && this->tabuleiro[a][b] != valor)
                {
                    pecasOpostas++;
                }

                a--;
                b++;

            } while (a != i && b != j);

            if(pecasOpostas == 0)
            {
                validade = false;
            } 

            validadeGlobal = validadeGlobal || validade;
        }
    } while (i != 0 && j != 7);
    
    i = linha;
    j = coluna;
    do
    {
        i++;
        j++;

        if(this->tabuleiro[i][j] == valor)
        {
            bool validade = true;
            int pecasOpostas = 0;

            int a = linha + 1;
            int b = coluna + 1;

            do
            {
                if(this->tabuleiro[a][b] == ' ')
                {
                    validade = false;
                }
                if(this->tabuleiro[a][b] != ' ' && this->tabuleiro[a][b] != valor)
                {
                    pecasOpostas++;
                }

                a++;
                b++;

            } while (a != i && b != j);

            if(pecasOpostas == 0)
            {
                validade = false;
            } 

            validadeGlobal = validadeGlobal || validade;
        }

    } while (i != 7 && j != 7);

    i = linha;
    j = coluna;
    do
    {
        i--;
        j--;

        if(this->tabuleiro[i][j] == valor)
        {
            bool validade = true;
            int pecasOpostas = 0;

            int a = linha - 1;
            int b = coluna - 1;

            do
            {
                if(this->tabuleiro[a][b] == ' ')
                {
                    validade = false;
                }
                if(this->tabuleiro[a][b] != ' ' && this->tabuleiro[a][b] != valor)
                {
                    pecasOpostas++;
                }

                a--;
                b--;

            } while (a != i && b != j);

            if(pecasOpostas == 0)
            {
                validade = false;
            } 

            validadeGlobal = validadeGlobal || validade;
        }

    } while (i != 0 && j != 0);

    i = linha;
    j = coluna;
    do
    {
        i++;
        j--;

        if(this->tabuleiro[i][j] == valor)
        {
            bool validade = true;
            int pecasOpostas = 0;

            int a = linha + 1;
            int b = coluna - 1;

            do
            {
                if(this->tabuleiro[a][b] == ' ')
                {
                    validade = false;
                }
                if(this->tabuleiro[a][b] != ' ' && this->tabuleiro[a][b] != valor)
                {
                    pecasOpostas++;
                }

                a++;
                b--;

            } while (a != i && b != j);

            if(pecasOpostas == 0)
            {
                validade = false;
            } 
        }

    } while (i != 8 && j != 0);

    if(this->tabuleiro[linha][coluna] != ' ')
    {
        validadeGlobal = false;
    }

    return validadeGlobal;
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

char Reversi::declararVencedor() {
    int quantidadeX = 0;
    int quantidadeO = 0;

    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(this->tabuleiro[i][j] == 'X')
            {
                quantidadeX++;
            }
            if(this->tabuleiro[i][j] == 'O')
            {
                quantidadeO++;
            }
        }
    }

    if(quantidadeX > quantidadeO)
    {
        return 'X';
    }
    if(quantidadeX < quantidadeO)
    {
        return 'O';
    }
    else
    {
        return 'E';
    }
}

void Reversi::inverterSimbolos(int linha, int coluna) {

    for(int i = 0; i < 8; i++)
    {
        if(i != coluna && this->tabuleiro[linha][coluna] == this->tabuleiro[linha][i])
        {
            bool validade = true;
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

            if(validade)
            {
                for(int j = std::min(i, coluna); j < std::max(i, coluna); j++)
                {
                    this->tabuleiro[linha][j] = this->tabuleiro[linha][coluna];
                }
            }
        }
    }

    for(int i = 0; i < 8; i++)
    {
        if(i != linha && this->tabuleiro[linha][coluna] == this->tabuleiro[i][coluna])
        {
            bool validade = true;
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

            if(validade)
            {
                for(int j = std::min(i, linha); j < std::max(i, linha); j++)
                {
                    this->tabuleiro[j][coluna] = this->tabuleiro[linha][coluna];
                }
            }
        }
    }

    int i = linha;
    int j = coluna;
    do
    {
        i--;
        j++;

        if(this->tabuleiro[i][j] == this->tabuleiro[linha][coluna])
        {
            bool validade = true;
            int pecasOpostas = 0;

            int a = linha - 1;
            int b = coluna + 1;

            do
            {
                if(this->tabuleiro[a][b] == ' ')
                {
                    validade = false;
                }
                if(this->tabuleiro[a][b] != ' ' && this->tabuleiro[a][b] != this->tabuleiro[linha][coluna])
                {
                    pecasOpostas++;
                }

                a--;
                b++;

            } while (a != i && b != j);

            if(pecasOpostas == 0)
            {
                validade = false;
            } 
            
            if(validade)
            {
                a = linha - 1;
                b = coluna + 1;

                do
                {
                    this->tabuleiro[a][b] = this->tabuleiro[linha][coluna];

                    a--;
                    b++;

                } while (a != i && b != j);
            }
        }
    } while (i != 0 && j != 7);
    
    i = linha;
    j = coluna;
    do
    {
        i++;
        j++;

        if(this->tabuleiro[i][j] == this->tabuleiro[linha][coluna])
        {
            bool validade = true;
            int pecasOpostas = 0;

            int a = linha + 1;
            int b = coluna + 1;

            do
            {
                if(this->tabuleiro[a][b] == ' ')
                {
                    validade = false;
                }
                if(this->tabuleiro[a][b] != ' ' && this->tabuleiro[a][b] != this->tabuleiro[linha][coluna])
                {
                    pecasOpostas++;
                }

                a++;
                b++;

            } while (a != i && b != j);

            if(pecasOpostas == 0)
            {
                validade = false;
            } 

            if(validade)
            {
                do
                {
                    this->tabuleiro[a][b] = this->tabuleiro[linha][coluna];

                    a++;
                    b++;

                } while (a != i && b != j);
            }
        }

    } while (i != 7 && j != 7);

    i = linha;
    j = coluna;
    do
    {
        i--;
        j--;

        if(this->tabuleiro[i][j] == this->tabuleiro[linha][coluna])
        {
            bool validade = true;
            int pecasOpostas = 0;

            int a = linha - 1;
            int b = coluna - 1;

            do
            {
                if(this->tabuleiro[a][b] == ' ')
                {
                    validade = false;
                }
                if(this->tabuleiro[a][b] != ' ' && this->tabuleiro[a][b] != this->tabuleiro[linha][coluna])
                {
                    pecasOpostas++;
                }

                a--;
                b--;

            } while (a != i && b != j);

            if(pecasOpostas == 0)
            {
                validade = false;
            } 

            if(validade)
            {
                do
                {
                    this->tabuleiro[a][b] = this->tabuleiro[linha][coluna];

                    a--;
                    b--;

                } while (a != i && b != j);
            }
        }

    } while (i != 0 && j != 0);

    i = linha;
    j = coluna;
    do
    {
        i++;
        j--;

        if(this->tabuleiro[i][j] == this->tabuleiro[linha][coluna])
        {
            bool validade = true;
            int pecasOpostas = 0;

            int a = linha + 1;
            int b = coluna - 1;

            do
            {
                if(this->tabuleiro[a][b] == ' ')
                {
                    validade = false;
                }
                if(this->tabuleiro[a][b] != ' ' && this->tabuleiro[a][b] != this->tabuleiro[linha][coluna])
                {
                    pecasOpostas++;
                }

                a++;
                b--;

            } while (a != i && b != j);

            if(pecasOpostas == 0)
            {
                validade = false;
            } 

            if(validade)
            {
                do
                {
                    this->tabuleiro[a][b] = this->tabuleiro[linha][coluna];

                    a++;
                    b--;

                } while (a != i && b != j);
            }
        }

    } while (i != 8 && j != 0);
}
#include "../include/Reversi.hpp"
#include <algorithm>
#include <iostream>
#include "../include/Jogador.hpp"

Reversi::Reversi() : Jogos(8, 8, 'X') {
    this->tabuleiro[3][3] = 'X';
    this->tabuleiro[3][4] = 'O';
    this->tabuleiro[4][3] = 'O';
    this->tabuleiro[4][4] = 'X';
}

Reversi::~Reversi() {}

bool Reversi::testarValidade(int linha, int coluna) {
    bool validadeGlobal = false;

    for(int i = 0; i < 8; i++)
    {
        if(i != coluna && jogadorAtual == this->tabuleiro[linha][i])
        {
            bool validade = true;
            int pecasOpostas = 0;

            for(int j = std::min(i, coluna) + 1; j <= std::max(i, coluna); j++)
            {
                if(this->tabuleiro[linha][j] == ' ')
                {
                    validade = false;
                }

                if(this->tabuleiro[linha][j] != ' ' && this->tabuleiro[linha][j] != jogadorAtual)
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
        if(i != linha && (jogadorAtual == this->tabuleiro[i][coluna]))
        {
            bool validade = true;
            int pecasOpostas = 0;
            
            for(int j = std::min(i, linha) + 1; j <= std::max(i, linha); j++)
            {
                if(this->tabuleiro[j][coluna] == ' ')
                {
                    validade = false;
                }

                if((this->tabuleiro[j][coluna] != ' ') && (this->tabuleiro[j][coluna] != jogadorAtual))
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

    int i = linha - 1;
    int j = coluna + 1;
    while (i >= 0 && j <= 7)
    {
        if(this->tabuleiro[i][j] == jogadorAtual)
        {
            bool validade = true;
            int pecasOpostas = 0;

            int a = linha - 1;
            int b = coluna + 1;

            while (a >= i && b <= j)
            {
                if(this->tabuleiro[a][b] == ' ')
                {
                    validade = false;
                }
                if(this->tabuleiro[a][b] != ' ' && this->tabuleiro[a][b] != jogadorAtual)
                {
                    pecasOpostas++;
                }

                a--;
                b++;

            }

            if(pecasOpostas == 0)
            {
                validade = false;
            } 

            validadeGlobal = validadeGlobal || validade;
        }

        i--;
        j++;
    }
    
    i = linha + 1;
    j = coluna + 1;
    while (i <= 7 && j <= 7)
    {
        if(this->tabuleiro[i][j] == jogadorAtual)
        {
            bool validade = true;
            int pecasOpostas = 0;

            int a = linha + 1;
            int b = coluna + 1;

            while (a <= i && b <= j)
            {
                if(this->tabuleiro[a][b] == ' ')
                {
                    validade = false;
                }
                if(this->tabuleiro[a][b] != ' ' && this->tabuleiro[a][b] != jogadorAtual)
                {
                    pecasOpostas++;
                }

                a++;
                b++;

            }

            if(pecasOpostas == 0)
            {
                validade = false;
            } 

            validadeGlobal = validadeGlobal || validade;
        }

        i++;
        j++;
    }

    i = linha - 1;
    j = coluna - 1;
    while (i >= 0 && j >= 0)
    {
        if(this->tabuleiro[i][j] == jogadorAtual)
        {
            bool validade = true;
            int pecasOpostas = 0;

            int a = linha - 1;
            int b = coluna - 1;

            while (a >= i && b >= j)
            {
                if(this->tabuleiro[a][b] == ' ')
                {
                    validade = false;
                }
                if(this->tabuleiro[a][b] != ' ' && this->tabuleiro[a][b] != jogadorAtual)
                {
                    pecasOpostas++;
                }

                a--;
                b--;

            }

            if(pecasOpostas == 0)
            {
                validade = false;
            } 

            validadeGlobal = validadeGlobal || validade;
        }

        i--;
        j--;

    } 

    i = linha + 1;
    j = coluna - 1;
    while (i <= 7 && j >= 0)
    {
        if(this->tabuleiro[i][j] == jogadorAtual)
        {
            bool validade = true;
            int pecasOpostas = 0;

            int a = linha + 1;
            int b = coluna - 1;

            while (a <= i && b >= j)
            {
                if(this->tabuleiro[a][b] == ' ')
                {
                    validade = false;
                }
                if(this->tabuleiro[a][b] != ' ' && this->tabuleiro[a][b] != jogadorAtual)
                {
                    pecasOpostas++;
                }

                a++;
                b--;

            }

            if(pecasOpostas == 0)
            {
                validade = false;
            } 

            validadeGlobal = validadeGlobal || validade;
        }

        i++;
        j--;

    } 

    if(this->tabuleiro[linha][coluna] != ' ' || linha < 0 || linha > 7 || coluna < 0 || coluna > 7)
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
            if(this->testarValidade(linha, coluna))
            {
                vitoria = false;
            }
        }
    }

    return vitoria;
}

void Reversi::alternarJogador() 
{
    if(jogadorAtual == 'X')
    {
        jogadorAtual = 'O';
    }
    else
    {
        jogadorAtual = 'X';
    }
}

void Reversi::executarJogada(int linha, int coluna)
{
    this->setCelula(linha, coluna, jogadorAtual);
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

    int i = linha - 1;
    int j = coluna + 1;
    while (i >= 0 && j <= 7)
    {
        if(this->tabuleiro[i][j] == this->tabuleiro[linha][coluna])
        {
            bool validade = true;
            int pecasOpostas = 0;

            int a = linha - 1;
            int b = coluna + 1;

            while (a >= i && b <= j)
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

            }

            if(pecasOpostas == 0)
            {
                validade = false;
            } 
            
            if(validade)
            {
                a = linha - 1;
                b = coluna + 1;

                while (a >= i && b <= j)
                {
                    this->tabuleiro[a][b] = this->tabuleiro[linha][coluna];

                    a--;
                    b++;

                }
            }
        }

        i--;
        j++;
    }
    
    i = linha + 1;
    j = coluna + 1;
    while (i <= 7 && j <= 7)
    {
        if(this->tabuleiro[i][j] == this->tabuleiro[linha][coluna])
        {
            bool validade = true;
            int pecasOpostas = 0;

            int a = linha + 1;
            int b = coluna + 1;

            while (a <= i && b <= j)
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

            }

            if(pecasOpostas == 0)
            {
                validade = false;
            } 

            if(validade)
            {
                a = linha + 1;
                b = coluna + 1;

                while (a <= i && b <= j)
                {
                    this->tabuleiro[a][b] = this->tabuleiro[linha][coluna];

                    a++;
                    b++;

                }
            }
        }

        i++;
        j++;

    }

    i = linha - 1;
    j = coluna - 1;
    while (i >= 0 && j >= 0)
    {
        if(this->tabuleiro[i][j] == this->tabuleiro[linha][coluna])
        {
            bool validade = true;
            int pecasOpostas = 0;

            int a = linha - 1;
            int b = coluna - 1;

            while (a >= i && b >= j)
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

            }

            if(pecasOpostas == 0)
            {
                validade = false;
            } 

            if(validade)
            {
                a = linha - 1;
                b = coluna - 1;

                while (a >= i && b >= j)
                {
                    this->tabuleiro[a][b] = this->tabuleiro[linha][coluna];

                    a--;
                    b--;

                }
            }
        }

        i--;
        j--;

    }

    i = linha + 1;
    j = coluna - 1;
    while (i <= 7 && j >= 0)
    {
        if(this->tabuleiro[i][j] == this->tabuleiro[linha][coluna])
        {
            bool validade = true;
            int pecasOpostas = 0;

            int a = linha + 1;
            int b = coluna - 1;

            while (a <= i && b >= j)
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

            }

            if(pecasOpostas == 0)
            {
                validade = false;
            } 

            if(validade)
            {
                a = linha + 1;
                b = coluna - 1;
                
                while (a <= i && b >= j)
                {
                    this->tabuleiro[a][b] = this->tabuleiro[linha][coluna];

                    a++;
                    b--;

                } 
            }
        }

        i++;
        j--;

    }
}

void Reversi::executarPartida(Jogador* jogador1, Jogador* jogador2) {  
    while(!this->testarVitoria())
    {
        if(this->jogadorAtual == 'X')
        {
            std::cout << "Turno de jogador " << jogador1->getApelido() << std::endl;
        }
        else 
        {
            std::cout << "Turno de jogador " << jogador2->getApelido() << std::endl;
        }

        std::cout << "*São aceitos apenas números dentro da dimensão do tabuleiro (1 a 8)*" << std::endl;

        int linha, coluna;
        std::cin >> linha >> coluna;

        if(linha < 1 || linha > 8 || coluna < 1 || coluna > 8)
        {
            std::cout << "ERRO: formato incorreto" << std::endl;
            continue;
        }

        linha--;
        coluna--;

        if(!this->existemJogadasValidas())
        {
            std::string apelido;
            if(jogadorAtual == 'X')
            {
                apelido = jogador1->getApelido();
            }
            else
            {
                apelido = jogador2->getApelido();
            }
            
            std::cout << "Não existem jogadas válidas para " << apelido << "." << std::endl;
            this->alternarJogador();
            continue;
        }

        if(this->testarValidade(linha, coluna))
        {
            this->executarJogada(linha,coluna);
            this->inverterSimbolos(linha, coluna);
            this->imprimirTabuleiro();
            this->alternarJogador();
        }
        else
        {
            std::cout << "ERRO: jogada inválida" << std::endl;
            continue;
        }
    }

    char vitoria = this->declararVencedor();

    if(vitoria == 'X')
    {
        std::cout << "Vitória de " << jogador1->getApelido() << "!" << std::endl;
        jogador1->registrarVitoria('R');
        jogador2->registrarDerrota('R');
    }
    else if(vitoria == 'O')
    {
        std::cout << "Vitória de " << jogador2->getApelido() << "!" << std::endl;
        jogador1->registrarDerrota('R');
        jogador2->registrarVitoria('R');
    }
    else if(vitoria == 'E')
    {
        std::cout << "Empate!" << std::endl;
    }
}

bool Reversi::existemJogadasValidas()
{
    bool validade = false;

    for (int linha = 0; linha < 8; linha++) {
        for (int coluna = 0; coluna < 8; coluna++) {
            if (this->testarValidade(linha, coluna)) {
                validade = true;
                break;
            }
        }
        if (validade) {
            break;
        }
    }

    return validade;
}
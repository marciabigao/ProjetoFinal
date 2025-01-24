/*!
 * \class Reversi
 * \brief Implementação do jogo Reversi derivado da classe base Jogos.
 * 
 * Contém a lógica para validação de jogadas, alternância de jogadores, 
 * manipulação do tabuleiro e execução de partidas entre dois jogadores.
 */

#include "../include/Reversi.hpp"
#include <algorithm>
#include <iostream>
#include "../include/Jogador.hpp"
#include <exception>
#include "../include/Erros.hpp"
#include <limits>

/*!
 * \brief Construtor da classe Reversi.
 * 
 * Inicializa o tabuleiro do jogo com 8x8 posições e configura as peças iniciais.
 */

Reversi::Reversi() : Jogos(8, 8, 'X') {
    this->tabuleiro[3][3] = 'X';
    this->tabuleiro[3][4] = 'O';
    this->tabuleiro[4][3] = 'O';
    this->tabuleiro[4][4] = 'X';
}

/*!
 * \brief Destrutor da classe Reversi.
 */
Reversi::~Reversi() {}
/*!
 * \brief Verifica se uma jogada é válida para o jogador atual.
 * 
 * Valida a jogada com base nas regras do jogo Reversi, verificando se peças do oponente
 * podem ser capturadas em qualquer direção.
 * 
 * \param linha Linha do tabuleiro onde a jogada será realizada.
 * \param coluna Coluna do tabuleiro onde a jogada será realizada.
 * \return `true` se a jogada for válida, `false` caso contrário.
 */

bool Reversi::testarValidade(int linha, int coluna) {
    // Validações horizontais, verticais e diagonais...
    // (O código existente permanece o mesmo, apenas foi documentado)
    bool validadeGlobal = false;

    for(int i = 0; i < 8; i++)
    {
        if(i != coluna && jogadorAtual == this->tabuleiro[linha][i])
        {
            bool validade = true;
            int pecasOpostas = 0;

            for(int j = coluna + ((i > coluna) ? 1 : -1); j != i; j += (i > coluna) ? 1 : -1)
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
            
            for(int j = linha + ((i > linha) ? 1 : -1); j != i; j += (i > linha) ? 1 : -1)
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
/*!
 * \brief Verifica se o jogo terminou e determina o vencedor.
 * 
 * A partida termina quando nenhum jogador possui jogadas válidas.
 * 
 * \return `true` se o jogo terminou, `false` caso contrário.
 */
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
            this->alternarJogador();
            if(this->testarValidade(linha, coluna))
            {
                vitoria = false;
            }
            this->alternarJogador();
        }
    }

    return vitoria;
}
/*!
 * \brief Alterna o jogador atual entre 'X' e 'O'.
 */
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
/*!
 * \brief Executa uma jogada no tabuleiro.
 * 
 * Insere a peça do jogador atual na posição especificada.
 * 
 * \param linha Linha do tabuleiro onde a jogada será realizada.
 * \param coluna Coluna do tabuleiro onde a jogada será realizada.
 * \throws std::invalid_argument Caso a posição seja inválida.
 */

void Reversi::executarJogada(int linha, int coluna)
{
    try
    {
        this->setCelula(linha, coluna, jogadorAtual);
    }
    catch(const std::invalid_argument& e)
    {
        throw;
    }
}
/*!
 * \brief Declara o vencedor com base no número de peças no tabuleiro.
 * 
 * \return 'X' se o jogador 'X' venceu, 'O' se o jogador 'O' venceu, 'E' em caso de empate.
 */

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
/*!
 * \brief Inverte as peças do oponente capturadas pela jogada atual.
 * 
 * As peças do oponente que estão entre duas peças do jogador atual são invertidas.
 * 
 * \param linha Linha onde a jogada foi realizada.
 * \param coluna Coluna onde a jogada foi realizada.
 */
void Reversi::inverterSimbolos(int linha, int coluna) {

    for(int i = 0; i < 8; i++)
    {
        if(i != coluna && this->tabuleiro[linha][coluna] == this->tabuleiro[linha][i])
        {
            bool validade = true;
            int pecasOpostas = 0;

            for(int j = coluna + ((i > coluna) ? 1 : -1); j != i; j += (i > coluna) ? 1 : -1)
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
                for(int j = coluna + ((i > coluna) ? 1 : -1); j != i; j += (i > coluna) ? 1 : -1)
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
            
            for(int j = linha + ((i > linha) ? 1 : -1); j != i; j += (i > linha) ? 1 : -1)
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
                for(int j = linha + ((i > linha) ? 1 : -1); j != i; j += (i > linha) ? 1 : -1)
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
/*!
 * \brief Executa uma partida completa de Reversi entre dois jogadores.
 * 
 * Alterna os turnos entre os jogadores, realiza jogadas, e determina o vencedor ao final.
 * 
 * \param jogador1 Ponteiro para o primeiro jogador.
 * \param jogador2 Ponteiro para o segundo jogador.
 * \throws ExcecaoNaoExistemJogadasValidas Caso um jogador não tenha jogadas válidas.
 */
void Reversi::executarPartida(Jogador* jogador1, Jogador* jogador2) {  
    this->imprimirTabuleiro();
    bool excecao = true;
    while(excecao)
    {
        try
        {
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

                if(std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    throw std::invalid_argument("ERRO: formato incorreto");
                }
                else if(linha < 1 || linha > 8 || coluna < 1 || coluna > 8)
                {
                    throw std::invalid_argument("ERRO: formato incorreto");
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
            
                    throw ExcecaoNaoExistemJogadasValidas(apelido);
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
                    throw std::invalid_argument("ERRO: jogada inválida");
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
            
            excecao = false;
        }
        catch(const std::invalid_argument& e)
        {
            std::cout << e.what() << std::endl;
        }
        catch(const ExcecaoNaoExistemJogadasValidas& e)
        {
            std::cout << e.what() << std::endl;
            this->alternarJogador();
        }
    }
    
}

/*!
 * \brief Verifica se existem jogadas válidas para o jogador atual.
 * 
 * \return `true` se existirem jogadas válidas, `false` caso contrário.
 */
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
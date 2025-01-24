#include "../include/JogodaVelha.hpp"
#include "../include/Jogador.hpp"
#include <iostream>
#include <exception>
#include <limits>

/*!
 * \class JogoDaVelha
 * \brief Implementação do jogo da velha derivada da classe base Jogos.
 * 
 * Contém a lógica para gerenciamento de tabuleiro, alternância de jogadores, 
 * validação de jogadas, e execução de partidas entre dois jogadores.
 */

/*!
 * \brief Construtor padrão da classe JogoDaVelha.
 * 
 * Inicializa o tabuleiro do jogo com 3x3 posições e define o jogador inicial como 'X'.
 */

JogoDaVelha::JogoDaVelha() : Jogos(3, 3, 'X') {}
/*!
 * \brief Destrutor da classe JogoDaVelha.
 */

JogoDaVelha::~JogoDaVelha() {}
/*!
 * \brief Verifica se uma jogada em determinada posição é válida.
 * \param linha Linha do tabuleiro onde a jogada será realizada.
 * \param coluna Coluna do tabuleiro onde a jogada será realizada.
 * \return `true` se a posição estiver vazia, `false` caso contrário.
 */

bool JogoDaVelha::testarValidade(int linha, int coluna) {

    if (this->tabuleiro[linha][coluna] != ' ') {

        return 0;

    }
    else
    {
        return 1;
    }
}
/*!
 * \brief Verifica se o jogador atual venceu a partida.
 * \return `true` se houver uma sequência vencedora no tabuleiro, `false` caso contrário.
 */

bool JogoDaVelha::testarVitoria() {
    
    ///testa vertical e horizontal
    for (int i = 0; i < 3; i++) {

        if ((this->tabuleiro[i][0] == jogadorAtual && this->tabuleiro[i][1] == jogadorAtual && this->tabuleiro[i][2] == jogadorAtual) ||
            (this->tabuleiro[0][i] == jogadorAtual && this->tabuleiro[1][i] == jogadorAtual && this->tabuleiro[2][i] == jogadorAtual)) {

            return true;
        }
    }

    ///testa as diagonais
    if ((this->tabuleiro[0][0] == jogadorAtual && this->tabuleiro[1][1] == jogadorAtual && this->tabuleiro[2][2] == jogadorAtual) ||
        (this->tabuleiro[0][2] == jogadorAtual && this->tabuleiro[1][1] == jogadorAtual && this->tabuleiro[2][0] == jogadorAtual)) {
        return true;
    }

    return false;
}
/*!
 * \brief Verifica se a partida terminou em empate.
 * \return `true` se todas as posições do tabuleiro estiverem preenchidas sem um vencedor, `false` caso contrário.
 */

bool JogoDaVelha::testarEmpate() {

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            ///testa se ainda há casas vazias (essas indicam que ainda há possíveis jogadas, então ainda não houve empate)
            if (this->tabuleiro[i][j] == ' ') { 
                return false; 
            }
        }
    }
    return true;
}
/*!
 * \brief Realiza uma jogada no tabuleiro para o jogador atual.
 * \param linha Linha onde a jogada será realizada.
 * \param coluna Coluna onde a jogada será realizada.
 */

void JogoDaVelha::executarJogada(int linha, int coluna) {
        this->tabuleiro[linha][coluna] = jogadorAtual;
}
/*!
 * \brief Alterna o jogador atual entre 'X' e 'O'.
 */
void JogoDaVelha::alternarJogador() {

    if (jogadorAtual == 'X')
    {
        jogadorAtual = 'O';
    } else {
        jogadorAtual = 'X';
    }

}
/*!
 * \brief Executa uma partida completa entre dois jogadores.
 * 
 * Realiza turnos alternados entre os jogadores, solicita entradas para jogadas e verifica 
 * as condições de vitória ou empate. Registra os resultados no final da partida.
 * 
 * \param jogador1 Ponteiro para o primeiro jogador.
 * \param jogador2 Ponteiro para o segundo jogador.
 */
void JogoDaVelha::executarPartida(Jogador* jogador1, Jogador* jogador2)
{
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

                std::cout << "Insira a linha e a coluna da sua jogada: " << std::endl;
                std::cout << "*São aceitos apenas números dentro da dimensão do tabuleiro (1 a 3)*" << std::endl;

                

                int linha, coluna;
                std::cin >> linha >> coluna;

                if(std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    throw std::invalid_argument("ERRO: formato incorreto");
                }
                else if(linha < 1 || linha > 3 || coluna < 1 || coluna > 3)
                {
                    throw std::invalid_argument("ERRO: formato incorreto");
                }

                linha--;
                coluna--;

                if(testarValidade(linha, coluna))
                {
                    this->executarJogada(linha, coluna);
                    this->imprimirTabuleiro();

                    if(!this->testarVitoria())
                    {
                        this->alternarJogador();
                    }
                }
                else
                {
                    throw std::invalid_argument("ERRO: jogada inválida");
                }

                if(this->testarEmpate())
                { 
                    break;
                }
            }

            if(this->testarVitoria())
            {
                if(this->jogadorAtual == 'X')
                {
                    std::cout << "Vitória de " << jogador1->getApelido() << "!" << std::endl;
                    jogador1->registrarVitoria('V');
                    jogador2->registrarDerrota('V');
                }
                if(this->jogadorAtual == 'O')
                {
                    std::cout << "Vitória de " << jogador2->getApelido() << "!" << std::endl;
                    jogador1->registrarDerrota('V');
                    jogador2->registrarVitoria('V');
                }
            }
            else
            {
                std::cout << "Empate!" << std::endl;
            }

            excecao = false;
        }
        catch(const std::invalid_argument& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
}

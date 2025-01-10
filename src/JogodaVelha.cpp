#include "../include/JogodaVelha.hpp"
#include "../include/Jogador.hpp"
#include <iostream>

using namespace std;

//inicializando o tabuleiro e o jogador atual (quem começa é o X)
JogoDaVelha::JogoDaVelha() : Jogos(3, 3), jogadorAtual('X') {}

JogoDaVelha::~JogoDaVelha() {}

bool JogoDaVelha::testarValidade(int linha, int coluna, char valor) {

    //note que as linhas e colunas vão da 0 até a 2 (3 espaços)

    if (linha < 0 || linha >= 3 || coluna < 0 || coluna >= 3) {

        cout << "Posicao escolhida está fora do tabuleiro!\n";
        return EXIT_FAILURE;

    }

    if (this->tabuleiro[linha][coluna] != ' ') {

        cout << "Posicao ja ocupada!\n";
        return EXIT_FAILURE;

    }

    return 0;
}

bool JogoDaVelha::testarVitoria() {
    
    //testa vertical e horizontal
    for (int i = 0; i < 3; i++) {

        if ((this->tabuleiro[i][0] == jogadorAtual && this->tabuleiro[i][1] == jogadorAtual && this->tabuleiro[i][2] == jogadorAtual) ||
            (this->tabuleiro[0][i] == jogadorAtual && this->tabuleiro[1][i] == jogadorAtual && this->tabuleiro[2][i] == jogadorAtual)) {

            return true;
        }
    }

    //testa as diagonais
    if ((this->tabuleiro[0][0] == jogadorAtual && this->tabuleiro[1][1] == jogadorAtual && this->tabuleiro[2][2] == jogadorAtual) ||
        (this->tabuleiro[0][2] == jogadorAtual && this->tabuleiro[1][1] == jogadorAtual && this->tabuleiro[2][0] == jogadorAtual)) {
        return true;
    }

    return false;
}

bool JogoDaVelha::testarEmpate() {

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            //testa se ainda há casas vazias (essas indicam que ainda há possíveis jogadas, então ainda não houve empate)
            if (this->tabuleiro[i][j] == ' ') { 
                return false; 
            }
        }
    }
    return true;
}

void JogoDaVelha::executarJogada(int linha, int coluna) {
        this->tabuleiro[linha][coluna] = jogadorAtual;
}

void JogoDaVelha::alternarJogador() {

    if (jogadorAtual == 'X')
    {
        jogadorAtual = 'O';
    } else {
        jogadorAtual = 'X';
    }

}

void JogoDaVelha::imprimirTabuleiro() const {

    //faz um loop e imprime um ponto se estiver vazio
    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {

            if (this->tabuleiro[i][j] == ' ')
            {
                cout << '.' << " ";

            } else {
                cout << this->tabuleiro[i][j] << " ";
            }

        }
        cout << endl; //quebra de linha após cada linha do tabuleiro
    }
}

void JogoDaVelha::executarPartida(Jogador* jogador1, Jogador* jogador2)
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

        std::cout << "*São aceitos apenas números dentro da dimensão do tabuleiro (1 a 3)*" << std::endl;

        int linha, coluna;
        std::cin >> linha >> coluna;

        if(linha < 1 || linha > 3 || coluna < 1 || coluna > 3)
        {
            std::cout << "ERRO: formato incorreto" << std::endl;
            continue;
        }

        linha--;
        coluna--;

        if(testarValidade(linha, coluna, this->jogadorAtual))
        {
            this->executarJogada(linha, coluna);
            //imprimir tabuleiro

            if(!this->testarVitoria())
			{
				this->alternarJogador();
			}
        }
        else
        {
            std::cout << "ERRO: jogada inválida" << std::endl;
			continue;
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
}
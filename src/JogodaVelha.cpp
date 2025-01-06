#include "JogodaVelha.hpp"
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

    if (testarValidade(linha, coluna, jogadorAtual)) 
    {
        this->tabuleiro[linha][coluna] = jogadorAtual;
    } else {
        cout << "ERRO: jogada inválida\n"; //mensagem conforme pedida no enunciado do tp
    }

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


#ifndef LIG4_H
#define LIG4_H

#include"Jogos.hpp"

class Lig4 : public Jogos{

private:
    int _numLinhas;
    int _numColunas;
    char _jogadorAtual;

public:

//Construtor e Destrutor
Lig4(int linhas, int colunas);
~Lig4();

//Metodo Validade
virtual bool testarValidade (int linha, int coluna, char valor) override; 

//Metodos Jogada
void executarJogada (int coluna);

//Metodos Jogador
void mudarJogador();
char jogadorAtual();

//Metodos Checagem do Jogo
virtual bool testarVitoria() override;
bool testarEmpate() const;

};

#endif
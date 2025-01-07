#ifndef LIG4_H
#define LIG4_H

#include"Jogos.hpp"

class Lig4 : public Jogos{

private:
    int numLinhas;
    int numColunas;
    char jogadorAtual;

public:

//Construtor e Destrutor
Lig4(int linhas, int colunas);
~Lig4();

//Metodo Dimensoes Tabuleiro
Lig4* definirDimensoes(int linhas, int colunas);

//Metodo Validade
virtual bool testarValidade (int linha, int coluna, char valor) override; //Nao uso linha, sera que uso ad hoc?

//Metodo Jogada
void executarJogada (int coluna, char jogadorAtual);

//Metodos Checagem do Jogo
virtual bool testarVitoria() override;
bool testarEmpate() const;

};

#endif
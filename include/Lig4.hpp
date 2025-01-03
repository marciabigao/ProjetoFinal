#ifndef LIG4_H
#define LIG4_H

#include"Jogos.hpp"

class Lig4 : public Jogos{

private:
    int numLinhas;
    int numColunas;
    int numVermelhos;
    int numAmarelos;

public:

//Construtor e Destrutor
Lig4(int linhas, int colunas);
~Lig4();

//Testar Tamanho Tabuleiro
void testarTamanho(int linhas, int colunas);

//Metodos Validade
virtual bool testarValidade (int linha , int coluna) const override;
virtual bool testarValidade (int coluna) const ;

//Metodos Jogada
virtual void lerJogada (int linha = -1, int coluna) override; // N implementei
virtual void lerJogada (int coluna, char jogador); 

//Metodos Checagem do Jogo
virtual bool testarVitoria() const override;
bool verificarSequencia(int linha, int coluna, char sentido);

};

#endif
#ifndef LIG4_H
#define LIG4_H

#include "Jogos.hpp"
#include "Jogador.hpp"

class Lig4 : public Jogos{

private:
    int _numLinhas;
    int _numColunas;
    char _jogadorAtual;

public:

    //Construtor e Destrutor
    Lig4(int linhas, int colunas);
    ~Lig4();

    //Recuperar parâmetros
    int getNumLinhas();
    int getNumColunas();
    char getJogadorAtual();

    //Metodo Validade
    virtual bool testarValidade (int linha, int coluna, char valor) override; 

    //Metodos Jogada
    void executarJogada(int coluna);
    void executarPartida(Jogador* jogador1, Jogador* jogador2);

    //Metodos Jogador
    void mudarJogador();
    char getJogadorAtual();

    //Metodos Checagem do Jogo
    virtual bool testarVitoria() override;
    bool testarEmpate() const;

};

#endif
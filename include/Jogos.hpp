#ifndef JOGOS_HPP
#define JOGOS_HPP

#include <iostream>
#include <vector>

class Jogos {
protected:
    std::vector<std::vector<char>> tabuleiro;

public:
    Jogos(int linhas, int colunas);
    virtual void lerJogada(int& linha, int&coluna) = 0;
    virtual bool testarValidade (int linha, int coluna) const = 0;
    virtual bool testarVitoria() const = 0;
    virtual void imprimirTabuleiro() const;
    virtual ~Jogos();
    void reiniciarTabuleiro();
};

#endif
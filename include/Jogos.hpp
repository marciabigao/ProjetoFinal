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

    const std::vector<std::vector<char>> & getTabuleiro() const;
    void setTabuleiro(const std::vector<std::vector<char>> & novoTabuleiro);
    void setCelula(int linha, int coluna, char valor);
    char getCelula(int linha, int coluna) const;

    void reiniciarTabuleiro();
};

#endif
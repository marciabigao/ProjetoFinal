#ifndef JOGOS_HPP
#define JOGOS_HPP

#include <iostream>
#include <vector>

class Jogos {
protected:
    std::vector<std::vector<char>> tabuleiro; 

public:
    // Construtor e Destrutor
    Jogos(int linhas, int colunas);
    virtual ~Jogos();
    
    //Tabuleiro
    const std::vector<std::vector<char>> & getTabuleiro() const;
    void setTabuleiro(const std::vector<std::vector<char>> & novoTabuleiro);
    virtual void imprimirTabuleiro() const;
    void reiniciarTabuleiro();

    //Celula
    char getCelula(int linha, int coluna) const;
    void setCelula(int linha, int coluna, char valor);
    
    //Metodos Virtuais 
    virtual void lerJogada(int linha, int coluna) = 0;
    virtual bool testarValidade (int linha, int coluna, char valor) = 0;
    virtual bool testarVitoria() = 0;

};

#endif
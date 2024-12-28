#include "Jogos.hpp"

Jogos::Jogos(int linhas, int colunas){
    tabuleiro.resize(linhas, std::vector<char>(colunas, ' '));
}

void Jogos::imprimirTabuleiro() const{
    for(const auto& linha : tabuleiro){
        for(const auto& celula : linha){
            std::cout << "|" << celula;
        }
        std::cout << "\n";
    }
    // Cada célula ocupa 2 caracteres + a | ao final (Ex: |X|O|X|)
    std::cout << std::string(tabuleiro[0].size() * 2 + 1, '-') << "\n";
} 

Jogos::~Jogos() {}

void Jogos::reiniciarTabuleiro(){
    for(auto& linha : tabuleiro){
        std::fill(linha.begin(), linha.end(), ' '); //fill vai preencher a linha com ' ' (espaço em branco)
    }
}
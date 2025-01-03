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

const std::vector<std::vector<char>>& Jogos::getTabuleiro() const{
    return tabuleiro;
}

void Jogos::setTabuleiro(const std::vector<std::vector<char>>& novoTabuleiro){
    tabuleiro = novoTabuleiro;
}

void Jogos::setCelula(int linha, int coluna, char valor){
    if (linha >= 0 && linha < static_cast<int>(tabuleiro.size()) && 
        coluna >= 0 && coluna < static_cast<int>(tabuleiro[0].size())) {
            tabuleiro[linha][coluna] = valor;
        }
    else{
        std::cerr << "Posição Inválida!\n";
    }
}

char Jogos::getCelula(int linha, int coluna) const {
    if (linha >= 0 && linha < static_cast<int>(tabuleiro.size()) &&
        coluna >= 0 && coluna < static_cast<int>(tabuleiro[0].size())) {
        char valor = tabuleiro[linha][coluna];
        if (valor != ' ') {
            std::cerr << "Posição Inválida: Já está ocupada com '" << valor << "'\n";
            return '\0'; // Caractere Nulo
        }
        return valor; 
    } 
        else {
        std::cerr << "Posição Inválida: Fora dos limites do tabuleiro\n";
        return '\0'; // Caractere Nulo
    }
}

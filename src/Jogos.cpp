#include "../include/Jogos.hpp"

Jogos::Jogos(int linhas, int colunas, char jogadorAtual){
    tabuleiro.resize(linhas, std::vector<char>(colunas, ' '));
    this->jogadorAtual = jogadorAtual;
}

Jogos::~Jogos() {}

const std::vector<std::vector<char>>& Jogos::getTabuleiro() const{
    return tabuleiro;
}

void Jogos::setTabuleiro(const std::vector<std::vector<char>>& novoTabuleiro){
    tabuleiro = novoTabuleiro;
}
 
void Jogos::imprimirTabuleiro() const{
    for(const auto& linha : tabuleiro){
        for(const auto& celula : linha){
            std::cout << "|" << celula;
        }
        std::cout << '|';
        std::cout << "\n";
    }
    // Cada célula ocupa 2 caracteres + a | ao final (Ex: |X|O|X|)
    std::cout << std::string(tabuleiro[0].size() * 2 + 1, '-') << "\n";
} 

void Jogos::reiniciarTabuleiro(){
    for(auto& linha : tabuleiro){
        std::fill(linha.begin(), linha.end(), ' '); //fill vai preencher a linha com ' ' (espaço em branco)
    }
}

char Jogos::getCelula(int linha, int coluna) const {
    if (linha >= 0 && linha < static_cast<int>(tabuleiro.size()) &&
        coluna >= 0 && coluna < static_cast<int>(tabuleiro[0].size())) {
        char valor = tabuleiro[linha][coluna];
        
        return valor; 
    } 
    else {
        throw std::invalid_argument("Posição Inválida: Fora dos limites do tabuleiro.");    }
}

void Jogos::setCelula(int linha, int coluna, char valor){
    if (linha >= 0 && linha < static_cast<int>(tabuleiro.size()) && 
        coluna >= 0 && coluna < static_cast<int>(tabuleiro[0].size())) {
            tabuleiro[linha][coluna] = valor;
        }
    else{
        throw std::invalid_argument("Posição Inválida!");    
        }
}


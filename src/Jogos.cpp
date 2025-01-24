#include "../include/Jogos.hpp"
/*!
 * \class Jogos
 * \brief Classe base para a implementação de jogos baseados em tabuleiros.
 * 
 * Define a estrutura básica de um jogo, incluindo gerenciamento do tabuleiro,
 * controle do jogador atual, e métodos para manipulação do estado do tabuleiro.
 */

/*!
 * \brief Construtor da classe Jogos.
 * 
 * Inicializa o tabuleiro com as dimensões especificadas e preenche com espaços em branco.
 * Define também o jogador que iniciará a partida.
 * 
 * \param linhas Número de linhas do tabuleiro.
 * \param colunas Número de colunas do tabuleiro.
 * \param jogadorAtual Jogador que iniciará a partida ('X' ou 'O').
 */
Jogos::Jogos(int linhas, int colunas, char jogadorAtual){
    tabuleiro.resize(linhas, std::vector<char>(colunas, ' '));
    this->jogadorAtual = jogadorAtual;
}
/*!
 * \brief Destrutor da classe Jogos.
 */

Jogos::~Jogos() {}
/*!
 * \brief Retorna o estado atual do tabuleiro.
 * 
 * \return Referência constante para o tabuleiro representado como uma matriz de caracteres.
 */

const std::vector<std::vector<char>>& Jogos::getTabuleiro() const{
    return tabuleiro;
}
/*!
 * \brief Define um novo estado para o tabuleiro.
 * 
 * Substitui o estado atual do tabuleiro pelo fornecido.
 * 
 * \param novoTabuleiro Matriz de caracteres representando o novo estado do tabuleiro.
 */
void Jogos::setTabuleiro(const std::vector<std::vector<char>>& novoTabuleiro){
    tabuleiro = novoTabuleiro;
}
/*!
 * \brief Imprime o tabuleiro no console.
 * 
 * Cada célula do tabuleiro é delimitada por barras verticais '|'. 
 * Uma linha de separação é adicionada abaixo do tabuleiro.
 */
 
void Jogos::imprimirTabuleiro() const{
    for(const auto& linha : tabuleiro){
        for(const auto& celula : linha){
            std::cout << "|" << celula;
        }
        std::cout << '|';
        std::cout << "\n";
    }
    /// Cada célula ocupa 2 caracteres + a | ao final (Ex: |X|O|X|)
    std::cout << std::string(tabuleiro[0].size() * 2 + 1, '-') << "\n";
} 
/*!
 * \brief Reinicia o tabuleiro, preenchendo todas as células com espaços em branco.
 */
void Jogos::reiniciarTabuleiro(){
    for(auto& linha : tabuleiro){
        std::fill(linha.begin(), linha.end(), ' '); //fill vai preencher a linha com ' ' (espaço em branco)
    }
}
/*!
 * \brief Retorna o valor de uma célula específica do tabuleiro.
 * 
 * Verifica os limites do tabuleiro antes de acessar a célula.
 * 
 * \param linha Índice da linha da célula.
 * \param coluna Índice da coluna da célula.
 * \return Valor contido na célula especificada.
 * \throws std::invalid_argument Caso a posição esteja fora dos limites do tabuleiro.
 */
char Jogos::getCelula(int linha, int coluna) const {
    if (linha >= 0 && linha < static_cast<int>(tabuleiro.size()) &&
        coluna >= 0 && coluna < static_cast<int>(tabuleiro[0].size())) {
        char valor = tabuleiro[linha][coluna];
        
        return valor; 
    } 
    else {
        throw std::invalid_argument("Posição Inválida: Fora dos limites do tabuleiro.");    }
}
/*!
 * \brief Define o valor de uma célula específica do tabuleiro.
 * 
 * Verifica os limites do tabuleiro antes de definir o valor na célula.
 * 
 * \param linha Índice da linha da célula.
 * \param coluna Índice da coluna da célula.
 * \param valor Novo valor para ser armazenado na célula.
 * \throws std::invalid_argument Caso a posição esteja fora dos limites do tabuleiro.
 */
void Jogos::setCelula(int linha, int coluna, char valor){
    if (linha >= 0 && linha < static_cast<int>(tabuleiro.size()) && 
        coluna >= 0 && coluna < static_cast<int>(tabuleiro[0].size())) {
            tabuleiro[linha][coluna] = valor;
        }
    else{
        throw std::invalid_argument("Posição Inválida!");    
        }
}


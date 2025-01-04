#include "../include/Jogos.hpp"
#include "../include/Reversi.hpp"
#include <iostream>

using namespace std;

int main(){

    Reversi reversi;

    
    cout << reversi.testarValidade(2, 3, 'O') << endl; // 1
    reversi.setCelula(2, 3, 'O');
    reversi.inverterSimbolos(2, 3);
    reversi.imprimirTabuleiro();
    cout << reversi.testarValidade(3, 2, 'X') << endl; // 0
    cout << reversi.testarValidade(2, 2, 'X') << endl; // 1
    reversi.setCelula(4, 2, 'X');
    reversi.inverterSimbolos(4,2);
    reversi.imprimirTabuleiro();

}
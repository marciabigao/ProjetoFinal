#include"Lig4.hpp"

const char AMARELO = 'A';
const char VERMELHO = 'V';

//Construtor
Lig4::Lig4(int linhas, int colunas): Jogos(linhas,colunas), _numLinhas(linhas),_numColunas(colunas),_jogadorAtual(AMARELO){}

//Destrutor
Lig4::~Lig4() {}

bool Lig4::testarValidade (int linha, int coluna, char valor){

    if(coluna < 0 || coluna >= _numColunas){
        std::cout << "Coluna escolhida está fora do tabuleiro!" << std::endl;
        return false;
    }
    else if(getCelula(0,coluna) != ' '){
        std::cout << "Coluna ja esta cheia!" << std::endl;
        return false;
    }
       
    return true;
}

//Executar Jogada 
void Lig4::executarJogada(int coluna){
    
    coluna--;

    if(coluna < 0 || coluna >= _numColunas){
        std::cout << "ERRO: Formato Incorreto" << std::endl;
        return;
    }
    else if (testarValidade(-1,coluna,_jogadorAtual)){
        
        for(int i= _numLinhas-1; i >= 0; i--){

            if(tabuleiro[i][coluna] == ' '){

                setCelula(i,coluna,_jogadorAtual);     
                return;
            }
        }
   }
}

void Lig4::mudarJogador(){

     if(_jogadorAtual == AMARELO)
        _jogadorAtual = VERMELHO;

    else 
        _jogadorAtual = AMARELO;

}

char Lig4::jogadorAtual(){
    return _jogadorAtual;
}

//Verifica condicoes de vitoria 
bool Lig4::testarVitoria(){ 

    for(int linha = 0; linha < _numLinhas; linha++){
        for(int coluna = 0; coluna < _numColunas; coluna++ ){

            if(getCelula(linha,coluna) == _jogadorAtual){
        
                if(coluna <= _numColunas - 4){

                if(   tabuleiro[linha][coluna + 0] == _jogadorAtual &&
                        tabuleiro[linha][coluna + 1] == _jogadorAtual &&
                        tabuleiro[linha][coluna + 2] == _jogadorAtual &&
                        tabuleiro[linha][coluna + 3] == _jogadorAtual )
                        return true;
                }

                if(linha <= _numLinhas - 4){

                    if( tabuleiro[linha + 0][coluna] == _jogadorAtual &&
                        tabuleiro[linha + 1][coluna] == _jogadorAtual &&
                        tabuleiro[linha + 2][coluna] == _jogadorAtual &&
                        tabuleiro[linha + 3][coluna] == _jogadorAtual )
                        return true;
                }

                if(coluna <= _numColunas - 4 && linha <= _numLinhas - 4){

                    if( tabuleiro[linha + 0][coluna + 0] == _jogadorAtual &&
                        tabuleiro[linha + 1][coluna + 1] == _jogadorAtual &&
                        tabuleiro[linha + 2][coluna + 2] == _jogadorAtual &&
                        tabuleiro[linha + 3][coluna + 3] == _jogadorAtual )
                        return true;
                }

                if(coluna <= _numColunas - 4 && linha >= 4){

                if( tabuleiro[linha - 0][coluna + 0] == _jogadorAtual &&
                        tabuleiro[linha - 1][coluna + 1] == _jogadorAtual &&
                        tabuleiro[linha - 2][coluna + 2] == _jogadorAtual &&
                        tabuleiro[linha - 3][coluna + 3] == _jogadorAtual )
                        return true;
                }
            }
        }
    }

    return false;
}

bool Lig4::testarEmpate() const{

    for(int linha =  0; linha < _numLinhas; linha++){
        for(int coluna = 0; coluna < _numColunas; coluna++){

            if(getCelula(linha,coluna) == ' ')
                return false;
        }
    }

    return true;
}
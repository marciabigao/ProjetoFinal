#include"Lig4.hpp"

const char JOGADOR1 = '1';
const char JOGADOR2 = '2';
const char AMARELO = 'A';
const char VERMELHO = 'V';
const char VERTICAL = 'U';
const char DIAGONAL = 'D';
const char HORIZONTAL = 'H';

//Construtor
Lig4::Lig4(int linhas, int colunas): Jogos(linhas,colunas), numLinhas(linhas),numColunas(colunas){}

//Destrutor
Lig4::~Lig4() {}

bool Lig4::testarValidade (int linha, int coluna) const {

    if(linha < 1 || coluna < 1 || linha >= numLinhas || coluna >= numColunas)
        return false;
    else if(getCelula(0,coluna) != ' ')
        return false;
    else   
        return true;

}

// Testar Validade
bool Lig4::testarValidade(int coluna) const{

    if(coluna < 1 || coluna >= numColunas)
        return false;
    else if(getCelula(0,coluna) != ' ')
        return false;
    else   
        return true;
}

 
//Ler Jogada (Revisar)
void Lig4::lerJogada(int coluna, char jogador){
    
    if(coluna < 0 || coluna >= numColunas)
        std::cout << "ERRO: formato incorreto" << std::endl;
    else if (testarValidade(coluna)){
        for(int i=numLinhas-1; i >= 0; i--){
            if(testarValidade(i,coluna)){
                if(jogador == JOGADOR1)
                    setCelula(i,coluna,'A');
                else if(jogador == JOGADOR2)
                    setCelula(i,coluna,'V');

                //setCelula(i,coluna,jogador == '1'? 'A':'V');
                
                return;
            }
        }
        std::cout << "ERRO: jogada inválida" << std::endl;
   }
}


//Verificar 4 caracteres em sequencia em qualquer direcao (FALTA ARRUMAR DIAGONAL)
bool Lig4::verificarSequencia(int linha, int coluna, char sentido){

    switch (sentido)
        {
        case HORIZONTAL:
            for(int i= 0; i<4; i++){
                if(tabuleiro[linha][coluna] != tabuleiro[linha][coluna+i])
                    return false;
            }
            return true;
            break;
        
        case VERTICAL:
             for(int i=0; i<4; i++){
                if(tabuleiro[linha][coluna] != tabuleiro[linha+i][coluna])
                    return false;
            }
            return true;
            break;

        case DIAGONAL:
            for(int i=0; i<4; i++){
                if(tabuleiro[linha][coluna] != tabuleiro[linha+i][coluna+i])
                    break;
            }
            return true;
            for(int i=0; i<4; i++){
                if(tabuleiro[linha][coluna] != tabuleiro[linha-i][coluna-i])
                    return false;
            }
            return true;
            break;
    }
}

//Verifica condicoes de vitoria (FALTA TERMINAR)
bool Lig4::testarVitoria() const{ 

    int flagLig4 = 0;

    for(const auto& linha : tabuleiro){
        for(int coluna = 0; coluna <= numColunas- 3; coluna++){
            for(int i=0; i<4; i++){
                if(linha[coluna] == linha[coluna + i])
                    flagLig4++;
                else{
                    flagLig4 = 0;
                    break;
                }
            }
            if (flagLig4 == 3)
                return true;
            else
                flagLig4 = 0;
        }
    }
}
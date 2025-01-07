#include"Lig4.hpp"

const char AMARELO = 'A';
const char VERMELHO = 'V';


//Construtor
Lig4::Lig4(int linhas, int colunas): Jogos(linhas,colunas), numLinhas(linhas),numColunas(colunas),jogadorAtual(AMARELO){}

//Destrutor
Lig4::~Lig4() {}

// Lig4* Lig4::definirDimensoes(int linhas, int colunas){

//     if(linhas == 7 && colunas == 6)
//         return new Lig4(7,6);
//     else if(linhas == 5 && colunas == 4)
//         return new Lig4(5,4);
//     else if(linhas == 6 && colunas == 5)
//         return new Lig4(6,5);
//     else if(linhas == 8 && colunas == 7)
//         return new Lig4(8,7);
//     else if(linhas == 9 && colunas == 7)
//         return new Lig4(9,7);
//     else if(linhas == 10 && colunas == 7)
//         return new Lig4(10,7);
//     else if(linhas == 8 && colunas == 8)
//         return new Lig4(8,8);
//     else{
//         std::cout << "Tabuleiro com dimensoes nao suportadas!" << std::endl;
//         return nullptr;
//     }
// }

bool Lig4::testarValidade (int linha, int coluna, char valor){

    if(coluna < 0 || coluna >= numColunas){
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
void Lig4::executarJogada(int coluna, char jogadorAtual){
    
    if(coluna < 0 || coluna >= numColunas)
        std::cout << "ERRO: Formato Incorreto" << std::endl;

    else if (testarValidade(-1,coluna,jogadorAtual)){
        
        for(int i= 0; i < numLinhas; i++){

            if(tabuleiro[i][coluna] == ' '){
                setCelula(i,coluna,jogadorAtual);
                
                if(jogadorAtual == AMARELO)
                    jogadorAtual = VERMELHO;
                else 
                    jogadorAtual = AMARELO;
                    
                return;
            }
        }
   }
}


//Verifica condicoes de vitoria 
bool Lig4::testarVitoria(){ 

    int linha;
    int flagSequencia = 0;

    for(int coluna = 0; coluna < numColunas; coluna++ ){

        for(int i= 0; i < numLinhas; i++){
            if(getCelula(i,coluna) == jogadorAtual)
                linha = i;
        }

        if(coluna <= numColunas - 3){

            for(int i = 0; i < 4; i++){

                if(flagSequencia < i)
                    break;

                if(tabuleiro[linha][coluna + i] == jogadorAtual)
                    flagSequencia++;     
            }

            if(flagSequencia == 3)
                return true;

            flagSequencia = 0;
        }

        if(linha <= numLinhas - 3){

            for(int i = 0 ; i < 4; i++){

                if(flagSequencia < i)
                    break;

                if(tabuleiro[linha + i][coluna] == jogadorAtual)
                    flagSequencia++;     
            }
            
            if(flagSequencia == 3)
                return true;

            flagSequencia = 0;
        }

        if(coluna <= numColunas - 3 && linha <= numLinhas - 3){

            for(int i = 0; i < 4; i++){

                if(flagSequencia < i)
                    break;

                if(tabuleiro[linha+i][coluna+i] == jogadorAtual)
                    flagSequencia++;     
            }
            
            if(flagSequencia == 3)
                return true;

            flagSequencia = 0;
        }

        if(coluna >= 3 && linha >= 3){

            for(int i = 0; i < 4; i++){

                if(flagSequencia < i)
                    return false;

                if(tabuleiro[linha-i][coluna+i] == jogadorAtual)
                    flagSequencia++;     
            }
            
            if(flagSequencia == 3)
                return true;
        }
    }
}

bool::Lig4::testarEmpate() const{

    for(int linha =  0; linha < numLinhas; linha++){
        for(int coluna = 0; coluna < numColunas; coluna++){

            if(getCelula(linha,coluna) == ' ')
                return false;
        }
    }

    return true;
}
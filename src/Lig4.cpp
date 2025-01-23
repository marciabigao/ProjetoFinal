#include "Lig4.hpp"
#include "Jogador.hpp"
#include <exception>
#include <limits>

const char AMARELO = 'A';
const char VERMELHO = 'V';

//Construtor
Lig4::Lig4(int linhas, int colunas): Jogos(linhas,colunas, AMARELO), _numLinhas(linhas),_numColunas(colunas){}

//Destrutor
Lig4::~Lig4() {}

int Lig4::getNumLinhas() {
	return this->_numLinhas;
}

int Lig4::getNumColunas() {
	return this->_numColunas;
}

char Lig4::getJogadorAtual(){
    return jogadorAtual;
}

bool Lig4::testarValidade (int linha, int coluna){

  try{
        
        if(getCelula(0,coluna) != ' '){
            std::cout << "Coluna ja esta cheia!" << std::endl;
            return false;
        }
    }catch(std::invalid_argument& e){
        throw;
        return false;
    }
       
    return true;
}

//Executar Jogada 
void Lig4::executarJogada(int linha, int coluna){
        
    for(int i= _numLinhas-1; i >= 0; i--){
        try{
            if(tabuleiro[i][coluna] == ' '){

                setCelula(i,coluna,this->jogadorAtual);  
                break;   
            }
        }catch(std::invalid_argument& e){
            throw;
        }
    }
}

void Lig4::alternarJogador(){

     if(jogadorAtual == AMARELO)
        jogadorAtual = VERMELHO;

    else 
        jogadorAtual = AMARELO;
}

//Verifica condicoes de vitoria 
bool Lig4::testarVitoria(){ 

    for(int linha = 0; linha < _numLinhas; linha++){
        for(int coluna = 0; coluna < _numColunas; coluna++ ){

            try{
                if(getCelula(linha,coluna) == jogadorAtual){
            
                    if(coluna <= _numColunas - 4){

                    if(   tabuleiro[linha][coluna + 0] == jogadorAtual &&
                            tabuleiro[linha][coluna + 1] == jogadorAtual &&
                            tabuleiro[linha][coluna + 2] == jogadorAtual &&
                            tabuleiro[linha][coluna + 3] == jogadorAtual )
                            return true;
                    }

                    if(linha <= _numLinhas - 4){

                        if( tabuleiro[linha + 0][coluna] == jogadorAtual &&
                            tabuleiro[linha + 1][coluna] == jogadorAtual &&
                            tabuleiro[linha + 2][coluna] == jogadorAtual &&
                            tabuleiro[linha + 3][coluna] == jogadorAtual )
                            return true;
                    }

                    if(coluna <= _numColunas - 4 && linha <= _numLinhas - 4){

                        if( tabuleiro[linha + 0][coluna + 0] == jogadorAtual &&
                            tabuleiro[linha + 1][coluna + 1] == jogadorAtual &&
                            tabuleiro[linha + 2][coluna + 2] == jogadorAtual &&
                            tabuleiro[linha + 3][coluna + 3] == jogadorAtual )
                            return true;
                    }

                    if(coluna <= _numColunas - 4 && linha >= 4){

                    if( tabuleiro[linha - 0][coluna + 0] == jogadorAtual &&
                            tabuleiro[linha - 1][coluna + 1] == jogadorAtual &&
                            tabuleiro[linha - 2][coluna + 2] == jogadorAtual &&
                            tabuleiro[linha - 3][coluna + 3] == jogadorAtual )
                            return true;
                    }
                }
            }catch(std::invalid_argument& e){
                throw;
            }
        }
    }

    return false;
}

bool Lig4::testarEmpate() const{

    for(int linha =  0; linha < _numLinhas; linha++){
        for(int coluna = 0; coluna < _numColunas; coluna++){
            try{
                if(getCelula(linha,coluna) == ' ')
                    return false;
            }catch(std::invalid_argument& e){
                throw;
            }
        }
    }

    return true;
}

void Lig4::executarPartida(Jogador* jogador1, Jogador* jogador2)
{
    bool excecao = true;
    while(excecao)
    {
        try
        {
            while(!this->testarVitoria())
            {
                if(this->getJogadorAtual() == AMARELO)
                {
                    std::cout << "Turno de jogador " << jogador1->getApelido() << std::endl;
                }
                else
                {
                    std::cout << "Turno de jogador " << jogador2->getApelido() << std::endl;
                }

                std::cout << "*São aceitos apenas números dentro da dimensão do tabuleiro (1 a " << this->_numColunas << ")*" << std::endl;

                int coluna;
                std::cin >> coluna;

                if(std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    throw std::invalid_argument("ERRO: formato incorreto");
                }
                else if(coluna < 1 || coluna > this->_numColunas)
                {
                    throw std::invalid_argument("ERRO: formato incorreto");
                }

                coluna--;

                if(this->testarValidade(-1,coluna))
                {
                    this->executarJogada(-1, coluna);
                    this->imprimirTabuleiro();

                    if(!this->testarVitoria())
                    {
                        this->alternarJogador();
                    }
                }
                else
                {
                    throw std::invalid_argument("ERRO: jogada inválida");
                }

                if(this->testarEmpate())
                { 
                    break;
                }
            }

            if(this->testarVitoria())
            {
                if(this->getJogadorAtual() == AMARELO)
                {
                    std::cout << "Vitória de " << jogador1->getApelido() << "!" << std::endl;
                    jogador1->registrarVitoria('L');
                    jogador2->registrarDerrota('L');
                }
                if(this->getJogadorAtual() == VERMELHO)
                {
                    std::cout << "Vitória de " << jogador2->getApelido() << "!" << std::endl;
                    jogador1->registrarDerrota('L');
                    jogador2->registrarVitoria('L');
                }
            }
            else
            {
                std::cout << "Empate!" << std::endl;
            }
        }
        catch(const std::invalid_argument& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
}
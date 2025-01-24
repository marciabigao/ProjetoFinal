#include "Lig4.hpp"
#include "Jogador.hpp"
#include <exception>
#include <limits>
/*!
 * \class Lig4
 * \brief Implementa o jogo Lig4, derivado da classe base Jogos.
 * 
 * Contém a lógica para execução de jogadas, validação de condições de vitória ou empate,
 * e controle do turno dos jogadores.
 */
const char AMARELO = 'A';/*!< Representa o jogador AMARELO. */
const char VERMELHO = 'V';/*!< Representa o jogador VERMELHO. */
/*!
 * \brief Construtor da classe Lig4.
 * 
 * Inicializa o tabuleiro do jogo com as dimensões especificadas e define o jogador inicial como AMARELO.
 * 
 * \param linhas Número de linhas do tabuleiro.
 * \param colunas Número de colunas do tabuleiro.
 */

///Construtor
Lig4::Lig4(int linhas, int colunas): Jogos(linhas,colunas, AMARELO), _numLinhas(linhas),_numColunas(colunas){}
/*!
 * \brief Destrutor da classe Lig4.
 */
///Destrutor
Lig4::~Lig4() {}
/*!
 * \brief Retorna o número de linhas do tabuleiro.
 * \return Número de linhas.
 */
int Lig4::getNumLinhas() {
	return this->_numLinhas;
}
/*!
 * \brief Retorna o número de colunas do tabuleiro.
 * \return Número de colunas.
 */

int Lig4::getNumColunas() {
	return this->_numColunas;
}
/*!
 * \brief Retorna o jogador atual.
 * \return Caractere representando o jogador atual ('A' ou 'V').
 */

char Lig4::getJogadorAtual(){
    return jogadorAtual;
}
/*!
 * \brief Verifica se uma jogada é válida.
 * 
 * Verifica se a coluna especificada ainda possui espaços disponíveis.
 * 
 * \param linha Não utilizado, mantido para compatibilidade com assinatura.
 * \param coluna Índice da coluna onde a jogada será realizada.
 * \return `true` se a jogada for válida, `false` caso contrário.
 */

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

/*!
 * \brief Executa uma jogada no tabuleiro.
 * 
 * Coloca o símbolo do jogador atual na coluna mais baixa disponível.
 * 
 * \param linha Não utilizado, mantido para compatibilidade com assinatura.
 * \param coluna Índice da coluna onde a jogada será realizada.
 */ 
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
/*!
 * \brief Alterna entre os jogadores AMARELO e VERMELHO.
 */
void Lig4::alternarJogador(){

     if(jogadorAtual == AMARELO)
        jogadorAtual = VERMELHO;

    else 
        jogadorAtual = AMARELO;
}

/*!
 * \brief Verifica se o jogador atual venceu a partida.
 * 
 * Realiza verificações nas direções horizontal, vertical e diagonais.
 * 
 * \return `true` se o jogador atual vencer, `false` caso contrário.
 */ 
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
/*!
 * \brief Verifica se a partida terminou em empate.
 * 
 * Retorna `true` se todas as posições do tabuleiro estiverem preenchidas.
 * 
 * \return `true` em caso de empate, `false` caso contrário.
 */
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
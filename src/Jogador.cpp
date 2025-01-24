#include "Jogador.hpp"
#include "../include/Erros.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>


/*!
 * \file Jogador.cpp
 * \brief Implementação dos métodos da classe Jogador.
 */

/*! \var std::map<std::string, Jogador*, Jogador::comparaMap> Jogador::jogadores
 *  \brief Mapa estático que armazena os jogadores cadastrados, indexados pelo apelido.
 */

std::map<std::string, Jogador*, Jogador::comparaMap> Jogador::jogadores;

/*!
 * \brief Retorna o nome completo do jogador.
 * \return Nome do jogador.
 */

std::string Jogador::getNome()

{
    return this->nomeJogador;
}
/*!
 * \brief Retorna o apelido do jogador.
 * \return Apelido do jogador.
 */
std::string Jogador::getApelido()
{
    return this->apelidoJogador;
}
/*!
 * \brief Retorna o número de vitórias no jogo Reversi.
 * \return Número de vitórias no Reversi.
 */
int Jogador::getVitoriasR()
{
    return this->vitoriasReversi;
}
/*!
 * \brief Retorna o número de derrotas no jogo Reversi.
 * \return Número de derrotas no Reversi.
 */

int Jogador::getDerrotasR()
{
    return this->derrotasReversi;
}

/*!
 * \brief Retorna o número de vitórias no jogo Lig4.
 * \return Número de vitórias no Lig4.
 */

int Jogador::getVitoriasLig()
{
    return this->vitoriasLig;
}

/*!
 * \brief Retorna o número de derrotas no jogo Lig4.
 * \return Número de derrotas no Lig4.
 */

int Jogador::getDerrotasLig()
{
    return this->derrotasLig;
}
/*!
 * \brief Retorna o número de derrotas no jogo da velha.
 * \return Número de derrotas no jogo da velha.
 */ 
int Jogador::getVitoriasJV()
{
    return this->vitoriasJVelha;
}
/*!
 * \brief Retorna o número de derrotas no jogo da velha.
 * \return Número de derrotas no jogo da velha.
 */
int Jogador::getDerrotasJV()
{
    return this->derrotasJVelha;
}
/*!
 * \brief Construtor que inicializa um jogador com nome e apelido.
 * \param nome Nome completo do jogador.
 * \param apelido Apelido do jogador.
 */
Jogador::Jogador(std::string nome, std::string apelido):
         nomeJogador(nome), apelidoJogador(apelido),
         vitoriasReversi(0), derrotasReversi(0),
         vitoriasLig(0), derrotasLig(0),
         vitoriasJVelha(0), derrotasJVelha(0) {}
/*!
 * \brief Construtor que inicializa um jogador com estatísticas completas.
 * \param nome Nome completo do jogador.
 * \param apelido Apelido do jogador.
 * \param vr Vitórias no Reversi.
 * \param dr Derrotas no Reversi.
 * \param vl Vitórias no Lig4.
 * \param dl Derrotas no Lig4.
 * \param vjv Vitórias no jogo da velha.
 * \param djv Derrotas no jogo da velha.
 */
Jogador::Jogador(std::string nome, std::string apelido, int vr, int dr,
                 int vl, int dl, int vjv, int djv):
         nomeJogador(nome), apelidoJogador(apelido),
         vitoriasReversi(vr), derrotasReversi(dr),
         vitoriasLig(vl), derrotasLig(dl),
         vitoriasJVelha(vjv), derrotasJVelha(djv) {}       
/*!
 * \brief Cadastra um jogador no mapa estático de jogadores.
 * \param apelido Apelido do jogador.
 * \throws ExcecaoJogadorRepetido Caso já exista um jogador com o mesmo apelido.
 * \note A memória para o jogador deve ser alocada antes de chamar este método, utilizando `new`.
 */

void Jogador::cadastraJogador(std::string apelido)
{
    if(jogadores.find(apelido) != jogadores.end())
    {
        Jogador* jogadorRepetido = this;
        delete jogadorRepetido;
        throw ExcecaoJogadorRepetido();
    }
    else
    {
        jogadores.insert({apelido, this});
        std::cout << "Jogador " << apelido << " inserido com sucesso" << std::endl;
    }
}
/*!
 * \brief Remove um jogador do mapa com base no apelido.
 * \param apelido Apelido do jogador a ser removido.
 */
void Jogador::removeJogador(std::string apelido)
{
    auto iterador = jogadores.find(apelido);
    delete iterador->second;
    jogadores.erase(iterador);
    std::cout << "Jogador " << apelido << " removido com sucesso" << std::endl;
}
/*!
 * \brief Atualiza as estatísticas de todos os jogadores em um arquivo de saída.
 * \throws std::ios_base::failure Caso o arquivo "estatisticas.txt" não possa ser aberto.
 * \note Método a ser chamado ao fim de cada execução (quando se seleciona FS)
 * \note para atualizar as estatísticas no arquivo "estatisticas.txt"
 */
void Jogador::atualizaEstatisticas()
{
    std::ofstream saida("estatisticas.txt", std::fstream :: out);
    char delimitador = '|';
    if(!saida.is_open())
    {
        saida.close();
        throw std::ios_base::failure("ERRO: falha ao abrir o arquivo de saída");
    }

    for(std::pair<const std::string, Jogador*>& player : jogadores)
    {
        saida << player.second->nomeJogador << delimitador << player.second->apelidoJogador << delimitador
              << player.second->vitoriasReversi << " " << player.second->derrotasReversi << " "
              << player.second->vitoriasLig << " " << player.second->derrotasLig << " "
              << player.second->vitoriasJVelha << " " << player.second->derrotasJVelha << " "
              << std::endl;
    }
    saida.close();
}
/*!
 * \brief Lê as estatísticas dos jogadores de um arquivo e insere os dados no mapa.
 * \throws std::ios_base::failure Caso o arquivo "estatisticas.txt" não possa ser aberto.
 * \throws std::invalid_argument Caso algum dado do arquivo não seja lido corretamente.
 * \note as informações de partidas anteriores armazenadas no arquivo, inserindo-as no map
 * \note Método a ser utilizado no início de uma nova execução para recuperar 
 */

void Jogador::leEstatisticas()
{
    std::ifstream entrada("estatisticas.txt", std::fstream :: in);
    if(!entrada.is_open())
    {
        entrada.close();
        throw std::ios_base::failure("ERRO: falha ao abrir o arquivo de entrada");
    }
    std::string dados;
    std::string nome, apelido;
    int vr, dr, vl, dl, vjv, djv;
    char delimitador = '|';
    while(std::getline(entrada, dados))
    {
        std::istringstream infoLida(dados);
        if(!(std::getline(infoLida, nome, delimitador)))
        {
            entrada.close();
            throw std::invalid_argument("ERRO: nome não foi lido com sucesso");
        }
        if(!(std::getline(infoLida, apelido, delimitador)))
        {
            entrada.close();
            throw std::invalid_argument("ERRO: apelido não foi lido com sucesso");
        }
        if(!(infoLida >> vr >> dr >> vl >> dl >> vjv >> djv))
        {
            entrada.close();
            throw std::invalid_argument("ERRO: dados numéricos não foram lidos com sucesso");
        }
        Jogador* jogadorInserido = new Jogador(nome, apelido, vr, dr, vl, dl, vjv, djv);
        jogadores.insert({apelido, jogadorInserido});
    }
    entrada.close();
}
/*!
 * \brief Imprime a listagem de jogadores ordenada por apelido ou nome.
 * \param opcao 'A' para ordenar por apelido, 'N' para ordenar por nome.
 * \throws ExcecaoMapVazio Caso o mapa de jogadores esteja vazio.
 */
void Jogador::imprimeListagem(char opcao)
{
    if(jogadores.empty())
    {
        throw ExcecaoMapVazio();
    }

    else if(opcao == 'A')
    {
        for(std::pair<const std::string, Jogador*>& player : jogadores)
        {
            std::cout << player.first << "|" << player.second->getNome() << std::endl;

            std::cout << "REVERSI - V: " << player.second->getVitoriasR() 
                      << " D: " << player.second->getDerrotasR() << std::endl;

            std::cout << "LIG4 - V: " << player.second->getVitoriasLig()
                      << " D: " << player.second->getDerrotasLig() << std::endl;

            std::cout << "VELHA - V: " << player.second->getVitoriasJV()
                      << " D: " << player.second->getDerrotasJV() << std::endl;

            std::cout << std::endl;
        }
    }

    else if(opcao == 'N')
    {
        std::vector <Jogador*> vetor;
        for(std::pair<const std::string, Jogador*>& player : jogadores)
        {
            ///copia os dados do map para um vector
            vetor.push_back(player.second);
        }
        ///utiliza o algoritmo sort com um comparador personalizado para
        ///ordenar os dados em função do atributo nomeJogador dos jogadores
        std::sort(vetor.begin(), vetor.end(), Jogador::comparaSort);

        for(Jogador* player : vetor)
        {
            std::cout << player->getApelido() << "|" << player->getNome() << std::endl;

            std::cout << "REVERSI - V: " << player->getVitoriasR() 
                      << " D: " << player->getDerrotasR() << std::endl;

            std::cout << "LIG4 - V: " << player->getVitoriasLig()
                      << " D: " << player->getDerrotasLig() << std::endl;

            std::cout << "VELHA - V: " << player->getVitoriasJV()
                      << " D: " << player->getDerrotasJV() << std::endl;

            std::cout << std::endl;
        }
    }
}
/*!
 * \brief Busca um jogador pelo apelido e retorna seu ponteiro.
 * \param apelido Apelido do jogador.
 * \return Ponteiro para o jogador encontrado (se existir)
 * \throws ExcecaoJogadorInexistente Caso o jogador não esteja cadastrado.
 * \note Método a ser utilizado quando se inicia uma partida para checar
 * \note Deve ser chamado uma vez para cada jogador, com seu apelido
 * \note Também deve ser utilizado antes de se chamar o método removeJogador
 */

Jogador* Jogador::buscaJogador(std::string apelido)
{
    auto iterador = jogadores.find(apelido);
    if(iterador == jogadores.end())
    {
        throw ExcecaoJogadorInexistente();
    }
    else
    {
        return iterador->second;
    }
}
/*!
 * \brief Libera a memória de todos os jogadores cadastrados.
 * \note Método a ser chamado ao final de cada execução (quando se seleciona FS)
 * \note para deletar a memória dinamicamente alocada dos elementos no map
 */

void Jogador::apagaMap()
{
    for(std::pair<const std::string, Jogador*>& player : jogadores)
    {
        delete player.second;
    }
}
/*!
 * \brief Atualiza as vitórias do jogador vencedor em uma partida.
 * \param jogo Identificador do jogo ('R', 'L', 'V').
 * \note Método a ser chamado para atualizar as vitórias do jogador vencedor em uma partida
 * \note Recebe o apelido do jogador e o jogo em que venceu 
 * \note ('R' para Reversi, 'L' para Lig4 e 'V' para Jogo da Velha)
 */

void Jogador::registrarVitoria(char jogo)
{
    auto iterador = jogadores.find(this->apelidoJogador);
    switch (jogo)
    {
        case('R'):
        {
            iterador->second->vitoriasReversi++;
        }
        break;
        
        case('L'):
        {
            iterador->second->vitoriasLig++;
        }
        break;
        
        case('V'):
        {
            iterador->second->vitoriasJVelha++;
        }
        break;
    }
}

/*!
 * \brief Atualiza as derrotas do jogador perdedor em uma partida.
 * \param jogo Identificador do jogo ('R', 'L', 'V').
 * \note Método a ser chamado para atualizar as derrotas do jogador perdedor em uma partida
 * \note Tem o mesmo funcionamento do método registrarVitoria 
 */

void Jogador::registrarDerrota(char jogo)
{
    auto iterador = jogadores.find(this->apelidoJogador);
    switch (jogo)
    {
        case('R'):
        {
            iterador->second->derrotasReversi++;
        }
        break;
        
        case('L'):
        {
            iterador->second->derrotasLig++;
        }
        break;
        
        case('V'):
        {
            iterador->second->derrotasJVelha++;
        }
        break;
    }
}
/*!
 * \brief Comparador personalizado para ordenar jogadores por nome.
 * \param a Ponteiro para o primeiro jogador.
 * \param b Ponteiro para o segundo jogador.
 * \return `true` se o nome do jogador `a` for menor que o de `b`.
 */
bool Jogador::comparaSort(Jogador* a, Jogador* b)
{
    std::string lowerA = a->getNome();
    std::string lowerB = b->getNome();

    for(char& c : lowerA)
    {
        c = std::tolower(c);
    }
    for(char& c : lowerB)
    {
        c = std::tolower(c);
    }
    if (lowerA < lowerB) return true;
    if (lowerA > lowerB) return false;
    return a < b;
}
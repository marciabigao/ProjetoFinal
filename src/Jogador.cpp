#include "Jogador.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

std::map<std::string, Jogador*> Jogador::jogadores;

std::string Jogador::getNome()
{
    return this->nomeJogador;
}

std::string Jogador::getApelido()
{
    return this->apelidoJogador;
}

int Jogador::getVitoriasR()
{
    return this->vitoriasReversi;
}

int Jogador::getDerrotasR()
{
    return this->derrotasReversi;
}

int Jogador::getVitoriasLig()
{
    return this->vitoriasLig;
}

int Jogador::getDerrotasLig()
{
    return this->derrotasLig;
}

int Jogador::getVitoriasJV()
{
    return this->vitoriasJVelha;
}

int Jogador::getDerrotasJV()
{
    return this->derrotasJVelha;
}

Jogador::Jogador(std::string nome, std::string apelido):
         nomeJogador(nome), apelidoJogador(apelido),
         vitoriasReversi(0), derrotasReversi(0),
         vitoriasLig(0), derrotasLig(0),
         vitoriasJVelha(0), derrotasJVelha(0) {}

Jogador::Jogador(std::string nome, std::string apelido, int vr, int dr,
                 int vl, int dl, int vjv, int djv):
         nomeJogador(nome), apelidoJogador(apelido),
         vitoriasReversi(vr), derrotasReversi(dr),
         vitoriasLig(vl), derrotasLig(dl),
         vitoriasJVelha(vjv), derrotasJVelha(djv) {}        

//A memória para o jogador a ser cadastrado deve ser alocada antes
//de se chamar o método, utilizando new 
void Jogador::cadastraJogador(std::string apelido)
{
    //se o apeldio buscado não estiver no map, retorna end (próxima posição vazia)
    if(jogadores.find(apelido) != jogadores.end())
    {
        std::cout << "ERRO: jogador repetido" << std::endl;
    }
    else
    {
        jogadores.insert({apelido, this});
        std::cout << "Jogador " << apelido << " inserido com sucesso" << std::endl;
    }
}

void Jogador::removeJogador(std::string apelido)
{
    if (this != nullptr)
    {
        auto iterador = jogadores.find(apelido);
        delete iterador->second;
        jogadores.erase(iterador);
        std::cout << "Jogador " << apelido << " removido com sucesso" <<std::endl;
    }
}

void Jogador::atualizaEstatisticas()
{
    std::ofstream saida("estatisticas.txt", std::fstream :: out);
    char delimitador = '|';
    if(!saida.is_open())
    {
        std::cout << "ERRO: falha ao abrir o arquivo de saída" << std::endl;
        return;
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

//Método a ser utilizado no início de uma nova execução para recuperar 
//as informações de partidas anteriores armazenadas no arquivo, inserindo-as no map
void Jogador::leEstatisticas()
{
    std::ifstream entrada("estatisticas.txt", std::fstream :: in);
    if(!entrada.is_open())
    {
        std::cout << "ERRO: falha ao abrir o arquivo de entrada" << std::endl;
        return;
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
            std::cout << "ERRO: nome não foi lido com sucesso" << std::endl;
            return;
        }
        if(!(std::getline(infoLida, apelido, delimitador)))
        {
            std::cout << "ERRO: apelido não foi lido com sucesso" << std::endl;
            return;
        }
        if(!(infoLida >> vr >> dr >> vl >> dl >> vjv >> djv))
        {
            std::cout << "ERRO: dados numéricos não foram lidos com sucesso" << std::endl;
            return;
        }
        Jogador* jogador_inserido = new Jogador(nome, apelido, vr, dr, vl, dl, vjv, djv);
        jogadores.insert({apelido, jogador_inserido});
    }
    entrada.close();
}

void Jogador::imprimeListagem(char opcao)
{
    if(opcao == 'A')
    {
        for(std::pair<const std::string, Jogador*>& player : jogadores)
        {
            std::cout << player.first << " " << player.second->getNome() << std::endl;

            std::cout << "REVERSI - V: " << player.second->getVitoriasR() 
                      << " D: " << player.second->getDerrotasR() << std::endl;

            std::cout << "LIG4 - V: " << player.second->getVitoriasLig()
                      << " D: " << player.second->getDerrotasLig() << std::endl;

            std::cout << "VELHA - V: " << player.second->getVitoriasJV()
                      << " D: " << player.second->getDerrotasJV() << std::endl;
        }
    }

    else if(opcao == 'N')
    {
        std::vector <Jogador*> vetor;
        for(std::pair<const std::string, Jogador*>& player : jogadores)
        {
            //copia os dados do map para um vector
            vetor.push_back(player.second);
        }
        //utiliza o algoritmo sort com uma função lambda personalizada para
        //ordenar os dados em função do atributo nomeJogador dos jogadores
        std::sort(vetor.begin(), vetor.end(),
        [](Jogador* jogadorA, Jogador* jogadorB)
        {
            return jogadorA->getNome() < jogadorB->getNome();
        });

        for(Jogador* player : vetor)
        {
            std::cout << player->getApelido() << " " << player->getNome() << std::endl;

            std::cout << "REVERSI - V: " << player->getVitoriasR() 
                      << " D: " << player->getDerrotasR() << std::endl;

            std::cout << "LIG4 - V: " << player->getVitoriasLig()
                      << " D: " << player->getDerrotasLig() << std::endl;

            std::cout << "VELHA - V: " << player->getVitoriasJV()
                      << " D: " << player->getDerrotasJV() << std::endl;
        }
    }
}

//Método a ser utilizado quando se inicia uma partida para checar
//se os jogadores inseridos de fato existem e fornecer ponteiros para eles.
//Deve ser chamado uma vez para cada jogador, com seu apelido
//Também deve ser utilizado antes de se chamar o método removeJogador
Jogador* Jogador::buscaJogador(std::string apelido)
{
    auto iterador = jogadores.find(apelido);
    if(iterador == jogadores.end())
    {
        std::cout << "ERRO: jogador " << apelido << " inexistente" << std::endl;
        return nullptr;
    }
    else
    {
        return iterador->second;
    }
}

//Método a ser chamado ao final de cada execução (quando se seleciona FS)
//para deletar a memória dinamicamente alocada dos elementos no map
void Jogador::apagaMap()
{
    for(std::pair<const std::string, Jogador*>& player : jogadores)
    {
        delete player.second;
    }
}

//Método a ser chamado para atualizar as vitórias do jogador vencedor em uma partida
//Recebe o apelido do jogador e o jogo em que venceu 
//('R' para Reversi, 'L' para Lig4 e 'V' para Jogo da Velha)
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

        default:
        {
            std::cout << "ERRO: jogo inválido" << std::endl;
        }
        break;
    }
}

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

        default:
        {
            std::cout << "ERRO: jogo inválido" << std::endl;
        }
        break;
    }
}
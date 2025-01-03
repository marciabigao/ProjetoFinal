#ifndef JOGADOR_H
#define JOGADOR_H
#include <string>
#include <map>

class Jogador
{
    private:
    std::string nomeJogador;
    std::string apelidoJogador;

    int vitoriasReversi, derrotasReversi;
    int vitoriasLig, derrotasLig;
    int vitoriasJVelha, derrotasJVelha;
    
    static std::map<std::string, Jogador*> jogadores;

    public:
    Jogador(std::string nome, std::string apelido);
    Jogador(std::string nome, std::string apelido, int vr, int dr, int vl, int dl, int vjv, int djv);
    ~Jogador();

    void cadastraJogador(std::string nome, std::string apelido);
    void removeJogador(std::string apelido);
    void imprimeListagem(char opcao);
    void leEstatisticas();
    void atualizaEstatisticas();
    Jogador* buscaJogador(std::string apelido);
    void apagaMap();
    void registrarVitoria(std::string apelidoVencedor, char jogo);
    void registrarDerrota(std::string apelidoPerdedor, char jogo);

    std::string getNome();
    std::string getApelido();
    int getVitoriasR();
    int getDerrotasR();
    int getVitoriasLig();
    int getDerrotasLig();
    int getVitoriasJV();
    int getDerrotasJV();
};
#endif
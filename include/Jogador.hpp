#ifndef JOGADOR_H
#define JOGADOR_H
#include <string>
#include <map>

/*!
 * \class Jogador
 * \brief Representa um jogador e suas estatísticas nos jogos.
 * 
 * A classe armazena informações como nome, apelido, estatísticas de vitórias e derrotas
 * para diferentes jogos. Também fornece métodos para manipulação e consulta desses dados.
 */
class Jogador
{
    private:
    std::string nomeJogador; ///< Nome completo do jogador.
    std::string apelidoJogador; ///< Apelido do jogador.

    int vitoriasReversi, derrotasReversi; ///< Estatísticas para o jogo Reversi.
    int vitoriasLig, derrotasLig; ///< Estatísticas para o jogo Lig4.
    int vitoriasJVelha, derrotasJVelha; ///< Estatísticas para o jogo da velha.

    /*!
     * \struct comparaMap
     * \brief Estrutura de comparação personalizada para ordenar jogadores por apelido.
     * 
     * Realiza a comparação ignorando maiúsculas e minúsculas.
     */
    struct comparaMap
    {
        bool operator()(const std::string& a, const std::string& b) const
        {
            std::string lowerA = a;
            std::string lowerB = b;

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
    };

    static std::map<std::string, Jogador*, comparaMap> jogadores; ///< Mapeamento de apelidos para jogadores.

    public:
    /*!
     * \brief Construtor que inicializa um jogador com nome e apelido.
     * \param nome Nome completo do jogador.
     * \param apelido Apelido do jogador.
     */
    Jogador(std::string nome, std::string apelido);

    /*!
     * \brief Construtor que inicializa um jogador com estatísticas completas.
     * \param nome Nome completo do jogador.
     * \param apelido Apelido do jogador.
     * \param vr Vitórias no Reversi.
     * \param dr Derrotas no Reversi.
     * \param vl Vitórias no Lig4.
     * \param dl Derrotas no Lig4.
     * \param vjv Vitórias no Jogo da Velha.
     * \param djv Derrotas no Jogo da Velha.
     */
    Jogador(std::string nome, std::string apelido, int vr, int dr, int vl, int dl, int vjv, int djv);

    /*!
     * \brief Imprime uma listagem dos jogadores.
     * \param opcao Opção de listagem (ex.: por vitórias ou derrotas).
     */
    static void imprimeListagem(char opcao);

    /*!
     * \brief Lê as estatísticas dos jogadores de um arquivo.
     */
    static void leEstatisticas();

    /*!
     * \brief Atualiza as estatísticas dos jogadores em um arquivo.
     */
    static void atualizaEstatisticas();

    /*!
     * \brief Busca um jogador pelo apelido.
     * \param apelido Apelido do jogador a ser buscado.
     * \return Ponteiro para o jogador encontrado ou nullptr se não existir.
     */
    static Jogador* buscaJogador(std::string apelido);

    /*!
     * \brief Remove todos os jogadores do mapa.
     */
    static void apagaMap();

    /*!
     * \brief Compara dois jogadores para ordenação.
     * \param a Ponteiro para o primeiro jogador.
     * \param b Ponteiro para o segundo jogador.
     * \return Verdadeiro se o jogador `a` deve vir antes de `b`.
     */
    static bool comparaSort(Jogador* a, Jogador* b);

    /*!
     * \brief Cadastra um jogador no mapa.
     * \param apelido Apelido do jogador.
     */
    void cadastraJogador(std::string apelido);

    /*!
     * \brief Remove um jogador do mapa pelo apelido.
     * \param apelido Apelido do jogador.
     */
    void removeJogador(std::string apelido);

    /*!
     * \brief Registra uma vitória para o jogador em um jogo específico.
     * \param jogo Identificador do jogo ('R', 'L', ou 'V').
     */
    void registrarVitoria(char jogo);

    /*!
     * \brief Registra uma derrota para o jogador em um jogo específico.
     * \param jogo Identificador do jogo ('R', 'L', ou 'V').
     */
    void registrarDerrota(char jogo);

    /*!
     * \brief Retorna o nome do jogador.
     * \return Nome completo do jogador.
     */
    std::string getNome();

    /*!
     * \brief Retorna o apelido do jogador.
     * \return Apelido do jogador.
     */
    std::string getApelido();

    /*!
     * \brief Retorna o número de vitórias no Reversi.
     * \return Número de vitórias no Reversi.
     */
    int getVitoriasR();

    /*!
     * \brief Retorna o número de derrotas no Reversi.
     * \return Número de derrotas no Reversi.
     */
    int getDerrotasR();

    /*!
     * \brief Retorna o número de vitórias no Lig4.
     * \return Número de vitórias no Lig4.
     */
    int getVitoriasLig();

    /*!
     * \brief Retorna o número de derrotas no Lig4.
     * \return Número de derrotas no Lig4.
     */
    int getDerrotasLig();

    /*!
     * \brief Retorna o número de vitórias no Jogo da Velha.
     * \return Número de vitórias no Jogo da Velha.
     */
    int getVitoriasJV();

    /*!
     * \brief Retorna o número de derrotas no Jogo da Velha.
     * \return Número de derrotas no Jogo da Velha.
     */
    int getDerrotasJV();
};

#endif

# tp-pds2
Trabalho Final de PDSII

**VISÃO GERAL**

O sistema produzido implementa três jogos: Reversi, Lig4 e Jogo da Velha. Além disso, conta com funcionalidades para cadastro e manutenção de registro/estatísticas dos jogadores que o utilizam. O código foi escrito inteiramente em linguagem C++. 

Para desenvolver o sistema foi necessário, primeiramente, estabelecer atribuições para cada um dos integrantes do grupo e datas para a "entrega" das partes que condizessem com as suas prioridades em termos de implementação. Nesse sentido, as classes Jogador (que trata dos jogadores em si) e Jogos (que é a classe abstrata da qual os demais jogos herdam) foram as primeiras a serem implementadas, uma vez que são essenciais para as demais. Em seguida, foram implementadas as classes Reversi, JogodaVelha e Lig4, e, após estarem prontas, o fluxo do jogo. Todas as partes foram, no decorrer do trabalho, modificadas, corrigidas e aprimoradas até que chegassem às suas versões finais. Nesse momento, foi possível finalizar as partes do trabalho que dependiam da completude do sistema, como a documentação e elaboração dos cartões CRC. 

Essencialmente, o fluxo do jogo (implementado no arquivo main.cpp) recebe informações de entrada (como operação desejada, nomes/apelidos de jogadores, jogadas em partidas, dentre outros), realiza o tratamento dessas informações e direciona a execução do programa para cada opção solicitada, fazendo as chamadas necessárias de métodos das outras classes. A execução das partidas em si é realizada pelo método executarPartida, presente e específico para cada uma das classes de jogos.

Uma funcionalidade extra implementada foi a possibilidade de escolha da dimensão do tabuleiro para o jogo Lig4. Ao escolher executar uma partida de Lig4, o jogador deve inserir o número de linhas e de colunas desejado para o tabuleiro.

**INSTRUÇÕES PARA COMPILAÇÃO E EXECUÇÃO**

Um compilador para linguagem C++ já deve estar instalado e disponível para uso em sua máquina, especificamente o compilador g++. Pode ser desejável o uso de uma IDE (como VSCode ou CodeBlocks) ou de um editor de texto para facilitar a visualização do código.

Para usar algum dos comandos do Makefile, que automatizam a compilação, basta escrever o comando desejado no terminal e apertar enter. Os comando disponíveis são:

make:

    Compila todos os objetos das classes e dos testes e gera o executável do programa(main.exe) e dos testes(testes.exe)

make main:

    Compila todos os objetos das classes e gera o executável do programa(main.exe)

make testes:

    Compila todos os objetos dos testes e gera o executável dos testes(testes.exe)

make run:

    Compila todos os objetos das classes, gera o executável do programa(main.exe) e executa o programa

make run_tests:

    Compila todos os objetos dos testes, gera o executável dos testes(testes.exe) e executa o programa dos testes

make clean:

    Remove todos os objetos da pasta obj e deleta qualquer executavel gerado

Para a execução, basta digitar ./nomeDoExecutavel (por exemplo, ./main ou ./testes) e teclar enter.

**CONSIDERAÇÕES E RELATÓRIO**

VITOR - classe Jogos e testes 

Para o início do trabalho, nosso grupo analisou quais métodos seriam necessários implementar na classe abstrata "Jogos" para abranger todos os jogos que seriam realizados. Na execução do código não houve uma grande dificuldade, devido a maioria dos métodos serem virtuais puros, entretanto, essa classe serve como base para todas as outras, o que poderia encadear várias complicações se acontecessem erros.
Como métodos virtuais puros foram implementados testarValidade, testarVitoria, executarJogada, alternarJogador e executarPartida
Foi feito também os getters e setters para getCelula e setCelula, getTabuleiro e setTabuleiro.
Quanto aos testes unitários, fiz os testes das classes "Jogo da Velha" e "Jogador", para isso, criei testes que cubrissem as funções essenciais de cada classe, para analisar se tudo estava correndo bem. Foram testados as condições de vitória (na diagonal, na linha e na coluna) e empate do jogo da velha e a inicialização do construtor. Para os testes da classe Jogador, testei o cadastro, a busca, a remoção e o registro de vitórias e derrotas em cada jogo.

LARA - classe Jogador

Para a classe Jogador, a primeira dificuldade foi definir a forma de armazenamento dos dados. Optou-se por utilizar um map, tendo como chaves strings com os apelidos dos jogadores (atributo apelidoJogador da classe) e como dados ponteiros para os objetos (jogadores) da classe. Essa escolha foi favorecida pela premissa de que os apelidos seriam únicos e compostos por uma só palavra. O map utilizado foi definido como um atributo estático da classe, uma vez que não diz respeito a um objeto específico, mas à classe como um todo.
Posteriormente, surgiram problemas relacionados à ordenação das chaves do map, uma vez que o comparador default para esse container, no caso de strings, é case-sensitive. Assim, o comparador, em geral, errava a ordem alfabética para strings que tivessem caracteres maiúsculos e minúsculos. Para lidar com essa questão, foi definido um comparador próprio (struct comparaMap da classe), que é case-insensitive (o que permite ordenar corretamente strings que tem caracteres maiúsculos e minúsculos), mas, ainda assim, consegue diferenciar strings que tem exatamente as mesmas letras e diferem somente em se elas são maiúsculas ou minúsculas (como "string" e "StRinG", por exemplo). O mesmo problema surgiu para o algoritmo sort usado no método imprimeListagem, sendo definido um comparador que segue o mesmo princípio para ser empregado nesse caso (método comparaSort da classe).
Outra questão relevante foi a desalocação da memória usada para os objetos da classe Jogador. Os ponteiros para esses objetos ficam todos armazenados no map da classe, de forma que, para garantir que a memória fosse desalocada, foi definido o método apagaMap, que itera sobre o map e apaga cada um dos ponteiros armazenados em seu campo de dados. Nos métodos removeJogador e cadastraJogador também foram definidos mecanismos específicos para lidar com a memória devidamente.
Por fim, para facilitar a sua utilização, os métodos da classe que operam sobre e lidam somente com o map (métodos imprimeListagem, leEstatisticas, atualizaEstatisticas, buscaJogador, apagaMap e comparaSort) foram definidos como métodos estáticos. Já os que tratam de objetos/instâncias específicos da classe (métodos cadastraJogador, removeJogador, registrarVitoria, registrarDerrota e métodos getters em geral) foram definidos como métodos não-estáticos. 

IZABELA - classe JogodaVelha

Primeiramente li as instruções do trabalho prático para o jogo que fiquei encarregada, o jogo da velha, tendo em vista que as classes Jogador e Jogos (classes mãe), já estavam prontas.
Assim, delimitei o que o jogo deveria conter: entrada e mensagens para jogadas inválidas, tratamento de exceções e impressão do tabuleiro a cada jogada. Os componentes/regras do jogo são: há 2 jogadores, 2 símbolos (X e O) e um tabuleiro com 9 espaços, ganha quem completar 3 símbolos seguidos, quer seja na horizontal, vertical, ou diagonal. Símbolos não podem colocados por cima de outros e, se nenhum jogador alcançar o objetivo, popularmente falamos que "deu velha". 
A primeira dificuldade encontrada foi para o método sobreescrito que testa a validade. Na classe base, o parâmetro valor é passado para o método. Contudo, no jogo da velha, esse parâmetro não é necessário para testar a validade, já que os valores (X e O) são alterados automaticamente a cada jogada com o novo método criado, alternar jogador. Para não ter de mudar a classe base, afetando outros jogos, apenas não utilizei esse parâmetro, mesmo ele estando na assinatura do método. Esse método apenas testa se a posição inserida, tanto das linhas, como das colunas, está entre 0 e 2, já que essa foi a forma em que o tabuleiro foi definido.

PAULO - classe Lig4 e Testes

Para programar a classe Lig4 em um primeiro momento tive que buscar conhecimento sobre o jogo, visto que não o reconheci somente pelo nome. Uma vez que entendi de qual jogo se tratava, comecei a implementação do mesmo baseado na classe abstrata Jogos. Como o tamanho do tabuleiro varia no jogo de Lig4, defini como atributos privados o número de linhas e de colunas para que conseguisse saber esse tamanho quando o objeto fosse instanciado. Depois disso os métodos básicos para o código, como os construtores, destrutores e os getters do número de linhas, de colunas, e do jogador atual, atributo da classe pai que seria necessário na lógica de programação. Em seguida reescrevi a função testar validade e a adaptei para o Jogo, para que soubesse quando uma coluna estivesse cheia ou uma entrada fosse inválida. Em seguida implementei o método para executar a partida, o qual foi o mais complicado, pois a jogada na coluna deve ser posicionada na linha mais baixa que não tem nenhuma peça, sendo então necessário considerar a "gravidade" no momento da programação. Implementei um método de alternar jogador, que apesar de simples é essencial para o funcionamento do jogo. Por fim, implementei os métodos que testam vitória e empate. No caso do método de empate a lógica foi relativamente simples, sendo necessário somente avaliar se todas as posições do tabuleiro foram preenchidas e nenhum jogador ganhou. Entretanto, para o método de vitória, foi necessário considerar todas as possibilidades de vitória, sendo necessário fazer quatro estruturas lógicas, uma para caso o jogador ganhasse com uma sequência de quatro peças na horizontal, uma para quatro peças na vertical e duas para as quatro peças na diagonal, pois é necessário considerar tanto uma diagonal ascendente quanto uma descendente.

Em relação aos testes, tive alguma dificuldade no começo, pois ainda não estava familiarizado com a biblioteca, mas uma vez que entendi os comandos e consegui fazer a utilização da biblioteca, o trabalho fluiu mais rapidamente. Após compreender o funcionamento, realizei os testes dos métodos do Lig4 e do Reversi, buscando testar a maioria dos métodos que consegui, e testando se os métodos funcionavam para todas as posições do tabuleiro. Em geral, o trabalho com os testes foi mais repetitivo e trabalhoso do que necessariamente difícil, pois era necessário entender os métodos empregados e então explorar os seus limites e buscar compreender se os mesmos funcionam quando devem e não funcionam quando não devem.

MÁRCIA - classe Reversi e fluxo do jogo

Para a classe/jogo Reversi, a primeira dificuldade foi em aprender o jogo, porque ele é complexo e ninguém do grupo o conhecia. A redefinição dos métodos virtuais foi bem tranquila. O que deu mais trabalho em toda a implementação foi a função testarValidade, porque o tabuleiro do jogo é muito grande e são necessárias verificações nas linhas, colunas e diagonais, averiguando se nesses sentidos existe uma peça da mesma cor da que se quer colocar, depois checar se não existem espaços vazios entre elas e se existe pelo menos uma peça da outra cor. Mas, depois que essa função foi resolvida, a sua lógia pode ser aplicada em outras (como o verificar vitoria e o inverter simbolos), facilitando o processo. Foram adicionados tres metodos (inverterSimbolos, declararVencedor e existeJogadaValida) que eram necessários para as regras do jogo.

Para o fluxo do jogo, a maior dificuldade foi, primeiro, entender o código que as outras pessoas do grupo tinham feito. Cada jogo é diferente e cada um tem a sua abordagem, então esse foi um processo complicado. O fluxo em si foi muito tranquilo, mas o que consumiu tempo foi padronizar as implementações dos jogos. Por exemplo, no meio do caminho percebi que os jogos tinham implementado métodos com a mesma finalidade e que não estavam na classe abstrata, então foi necessário mudar isso. Vi que alguns métodos estavam fazendo coisas que eram do fluxo, e tive que mudar também. Vi que um dos jogos estava diferente quanto à implementação das vezes nos jogadores e dessa alternância, então tive que mudar. A maior dificuldade foi em relação a esses conflitos.

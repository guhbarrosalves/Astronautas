# Diário da atividade

Escreva com as suas palavras. Frases curtas bastam. Não cole a conversa inteira
com a IA. Cole só os pedidos que você enviou.

## Ambiente

- Versão do OpenCode (`opencode --version`): 1.18.29
- Modelo usado: Big Pickle

## Parte 1: antes de programar

- O que cada classe guarda: A classe Astronauta guarda o nome, cpf, idade do astronauta e se ele está vivo ou não e se está disponível para uma missão.
A classe Voo guarda o código do voo, o estado dele, que começa planejado, quando está ocorrendo fica com status "em curso" e termina ou com sucesso ou com explosão. Por fim, ela guarda um vetor com os cpfs dos astronautas que estão dentro do voo.
A classe agência guarda um vetor com todos os astronautas que pertencem a ela, igualmente como fazem com os voos.
- O que acontece em `LANCAR_VOO`, em palavras: LANCAR_VOO é um comando que lança o voo cujo código vem em seguida. Ela verifica se o voo existe, confere seu estado, se tem alguém a bordo, confere os astronautas e depois lança a embarcação e muda o estado do voo e o estado dos astronautas.
- Uma dúvida que eu tinha antes de começar: Li o enunciado, reli, mas mesmo assim não compreendi muito bem. Vou tentar começar a fazer o desenho para ter uma visualização melhor de tudo que vai ser feito, para ver se consigo enxergar as coisas de outra forma.

## Parte 1: uso de IA para entender algo

- O que perguntei (ou "não usei"): Tirei uma dúvida porque estava com uma dificuldade de encontrar a solução para um problema de implementar a função CADASTRAR_ASTRONAUTA.
- O que aprendi: Aprendi a olhar os tipos dos métodos e os valores que eles retornam.
- Não consegui estruturar o código para conseguir realizar o método ListarVoos, bem como o método ListarMortos, por isso, pedi que ela implementasse ele para mim.
- Usei a IA para compreender como implementar o método adicionar_astronauta. Eu estava pensando, mas não estava conseguindo organizar o código para fazer isso. Por causa disso, percebi um erro no código, mas especificamente no retorno de BuscarAstronauta e BuscarVoo, que estava sendo 1 ao invés da posição, ou seja, i.
- O que eu aprendi: Aprendi a olhar com mais detalhes para os métodos que fariam Adicionar_Astronauta depender deles.
- Usei a IA para poder implementar a linha 209, porque não estava sabendo conectar tudo, porque via que estava precisando de algo da classe Astronauta para poder acessar o método esta_Vivo(), mas não conseguia encontrar a solução. Ela me mostrou que apenas precisava usar o buscarAstronauta combinado do vetor astronautas.
- Estava com um problema no teste_06. Era dado um comando para lançar o voo 10 com o astronauta 111 e lançava normalmente. Quando ele ia lançar o voo 20, que tinha o 111 e o 333; mas pós o astronauta 111 ser tirado, ele não permitia porque o astronauta 333 estava indisponível, mas ele não havia sido lançado em voo algum. Fiquei algum tempo pensando e não compreendi. Usei a IA pra poder encontrar o erro para mim, e o erro acontecia porque no comando lancarvoo, o comando que mudava a disponibilidade do astronauta estava dentro do for que verificava, ou seja, o comando verificava e embarcava o astronauta juntos.

## Primeiro contato: revisão sem editar

- As três melhorias que a IA sugeriu, em uma linha cada: Usar true/false em vez de 1/0 para booleanos - Não buscar duas vezes a mesma coisa (linhas 126-128) e para lancarVoo, explodirVoo e finalizarVoo - Evitar repetição de código (DRY).
- A que escolhi e por quê: Escolhi não buscar duas vezes a mesma coisa, porque evitar repetição de código visava criar uma função.
- O que mudou no código, e se os seis testes continuaram passando: Mudou que ao invés de eu chamar BuscarVoo ou BuscarAstronauta de novo no primeiro if, eu chamava posVoo e posAstronauta. Os seis testes passaram.
- O que entendi que não sabia antes: Não entendi nada que não sabia antes, mas apenas uma noção de otimização de código, para evitar chamar algo que já tinha chamado anteriormente.

## Missão 1: LISTAR_ASTRONAUTAS e HISTORICO

- Primeira mensagem (o pedido do plano): 
Este programa em C++11 controla astronautas e voos de uma agência espacial.
Ele lê comandos da entrada padrão. As classes Astronauta, Voo e Agencia estão
em src/main.cpp. Os testes em testes/parte1 passam.
Quero dois comandos novos: LISTAR_ASTRONAUTAS e HISTORICO cpf. A saída exata
está abaixo.

LISTAR_ASTRONAUTAS mostra todos os astronautas em três grupos, na ordem de cadastro dentro de cada grupo. No grupo disponiveis entram os vivos que não estão em nenhum voo em curso.
No grupo em voo entram os vivos que estão em um voo em curso, com o código desse voo. No grupo mortos entram os mortos. Grupo vazio mostra (nenhum).
Os dois exemplos abaixo são do mesmo cenário: Ana voou no 10, que terminou com sucesso, e agora está no 20, em curso. Bruno morreu em outro voo.

LISTA DE ASTRONAUTAS
== disponiveis ==
333 Carla Souza (28 anos)
== em voo ==
111 Ana Maria (30 anos) - voo 20
== mortos ==
222 Bruno Costa (35 anos)

HISTORICO cpf mostra os voos dos quais o astronauta participou, com o estado atual de cada um, na ordem de cadastro dos voos. Participou significa que o voo foi lançado com ele a bordo. Voo só planejado não aparece. Sem voos: (nenhum voo). CPF desconhecido: ERRO: astronauta 999 nao cadastrado.

HISTORICO DE 111 Ana Maria
voo 10: finalizado com sucesso
voo 20: em curso

Teste: bash testes/testar.sh missao1. Depois: bash testes/testar.sh parte1.

Não mude nenhum comando que já existe nem a saída deles. Não use nada fora da
biblioteca padrão.

Vou conferir com bash testes/testar.sh missao1 e depois com
bash testes/testar.sh parte1.

Antes de editar, me diga quais arquivos e quais métodos você vai criar ou
alterar, e por quê.

- O plano que a IA apresentou, resumido: 
Métodos novos na classe Agencia:

void listarAstronautas() — Percorre o vector astronautas em ordem de cadastro e classifica cada um em um dos três grupos:

disponível: vivo e não está em nenhum voo com estado "em curso"

em voo: vivo e está em pelo menos um voo "em curso" (mostra o código desse voo)

morto: não vivo

void historico(string cpf) — Busca o astronauta pelo CPF. Se não existe, imprime ERRO. Se existe, percorre o vector voos em ordem de cadastro e imprime só os voos onde o astronauta estava a bordo e que já foram lançados (estado diferente de "planejado"). Se não há voos, imprime (nenhum voo).

Na main():

Adicionar else if para "LISTAR_ASTRONAUTAS" → chama agencia.listarAstronautas()

Adicionar else if para "HISTORICO" → lê o CPF, chama agencia.historico(cpf)

- Mudei algo no plano antes de liberar? Não.
- Resultado de `testar.sh missao1` e de `testar.sh parte1`: Todos os testes passaram.
- Precisei refazer? O que mudou no pedido: Não.

## Missão 2: SALVAR e CARREGAR

- Primeira mensagem:
Este programa em C++11 controla astronautas e voos de uma agência espacial.
Ele lê comandos da entrada padrão. As classes Astronauta, Voo e Agencia estão
em src/main.cpp. Os testes em testes/parte1 e testes/testar.sh missao1 passam.

Quero dois comandos novos: CARREGAR (nome_do_arquivo) e SALVAR (nome_do_arquivo).

SALVAR nome_do_arquivo grava todos os dados em um arquivo de texto e imprime OK: dados salvos em nome_do_arquivo. Se não conseguir abrir o arquivo para escrita: ERRO: nao foi possivel salvar em nome_do_arquivo.

CARREGAR nome_do_arquivo substitui todos os dados atuais pelos do arquivo e imprime OK: dados carregados de nome_do_arquivo. Se o arquivo não existir: ERRO: nao foi possivel carregar de nome_do_arquivo, e os dados atuais continuam como estavam.

O formato do arquivo é escolha sua, mas antes de escolher, me diga qual seria e porque, desde que seja texto e que carregar depois de salvar reconstrua tudo: astronautas com vivo e disponível, voos com estado e lista de CPFs.

Além disso, me mostre o formato com um exemplo e explique como o programa reconstrói os objetos ao ler.

Teste: bash testes/testar.sh missao2. 
Depois: bash testes/ testar.sh parte1.

Não mude nenhum comando que já existe nem a saída deles. Não use nada fora da
biblioteca padrão.
Vou conferir com bash testes/testar.sh parte1 e depois com
bash testes/testar.sh missao2. Antes de editar, me diga quais arquivos e quais métodos você vai criar ou alterar, e por quê.

- O plano, resumido: 
Formato do Arquivo: Utiliza blocos delimitados (ASTRONAUTAS/FIM_ASTRONAUTAS e VOOS/FIM_VOOS), salvando dados simples por linha e separando CPFs de voos por vírgulas.

Reconstrução ao Ler: O sistema lê os dados salvos utilizando operadores padrão e getline para nomes, recriando os objetos conforme o arquivo.

Modificações Necessárias:

Adicionar setters nas classes Astronauta e Voo.

Criar os métodos salvar e carregar na classe Agencia.

Atualizar a main() com os comandos SALVAR e CARREGAR.

Restrições: Métodos existentes, saídas de comandos e arquivos em testes/ não devem ser modificados.

- O formato do arquivo (cole cinco linhas do `dados_teste.txt`): 
ASTRONAUTAS
111 30 1 1 Ana Maria
222 35 0 0 Bruno Costa
333 28 1 1 Carla Souza
FIM_ASTRONAUTAS

- Resultado de `testar.sh missao2` e de `testar.sh parte1`: Todos os testes passaram.
- Precisei refazer? O que mudou no pedido: Não.

## Missão 3: RELATORIO

- Primeira mensagem:
- O plano, resumido:
- Resultado de `testar.sh missao3` e de `testar.sh parte1`:
- Precisei refazer? O que mudou no pedido:

## Missão 4: livre

- O que escolhi e por quê:
- O comando novo, a saída que eu esperava e o nome do meu arquivo de comandos
  (escritos antes de pedir):
- Primeira mensagem:
- O que veio, comparado com o que eu esperava:
- `testar.sh parte1` continuou passando?
- Aceitei, ajustei ou descartei? Por quê:

## Fechamento

- O que a IA fez que eu não conseguiria fazer sozinho nesse prazo:
- Onde ela errou ou fez algo que eu não pedi:
- O que eu faria diferente da próxima vez:

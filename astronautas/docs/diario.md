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
- O plano que a IA apresentou, resumido:
- Mudei algo no plano antes de liberar?
- Resultado de `testar.sh missao1` e de `testar.sh parte1`:
- Precisei refazer? O que mudou no pedido:

## Missão 2: SALVAR e CARREGAR

- Primeira mensagem:
- O plano, resumido:
- O formato do arquivo (cole cinco linhas do `dados_teste.txt`):
- Resultado de `testar.sh missao2` e de `testar.sh parte1`:
- Precisei refazer? O que mudou no pedido:

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

1. Tema
Desenvolver um programa para efectuar a gestão de um parque de estacionamento, fazendo a
gestão optimizada dos lugares.

2. Funcionalidades propostas
Descrição dos objectivos gerais e das funcionalidades propostas, enquadradas no tema
escolhido
• Inserir carros no estacionamento;
• Remover carros;
• Indicar o número de carros no estacionamento;
• Indicar o número total de lugares disponíveis;
• Listar os carros;

3. Estrutura analítica do projecto
O projecto foi dividido em tarefas e sub-tarefas mais simples, e estas foram distribuídas
por cada elemento do grupo. O projecto foi gravado em ficheiros (“Parque.dat”). Todas
as funcionalidades propostas foram implementadas e foram também implementadas
funcionalidades extras que serão apresentadas mais à frente neste relatório. As
estruturas utilizadas estão no de um header file (carro.h).

4. Funcionalidades implementadas
Ao longo do projecto foram implementadas novas funcionalidades, tais como:
•Criar um menu principal e inicial;
•Imprimir os lugares (livres e ocupados);
•Pesquisar o carro;
•Estacionar automaticamente;
•Representação do parque;
•Guardar e ler os dados em ficheiros.
•Criar regras ou indicações para o utilizador usar o projecto.

Descrição das funcionalidades implementadas:
1)Função para um menu inicial
Essa função vai ser a primeira a ser apresentada no nosso programa onde podemos escolher
varias opções, a primeira para aceder a administração do parque (Menu principal), a segunda
para aceder as informações do nosso programa.
2)Função administrar (Menu Principal)
Função que mostra em primeiro lugar quantos lugares livres ainda existem para o utilizador
estacionar o carro. Para isso acontecer, percorremos a matriz tridimensional e se a variável
estado for igual a 0 a variável j é incrementada. Se j for diferente de 0 ele imprime quantos
lugares estão livres, caso contrario imprime que o parque está cheio.

3)Função desenhar o parque
Função que imprime um "desenho" do parque , representando o lugar ocupado com um
asterisco e o lugar livre com um espaço.

4)Função estacionar
Esta função vai pedir para introduzir o piso, fila e lugar onde o utilizador quer estacionar o
carro, se o lugar estiver ocupado ele informa que não pode estacionar. De seguida tem que
introduzir a marca do seu carro e a matricula o tipo 00-00-AA senão será considerado um
matricula inválida. Nesta função também é armazenado o ano, mês, dia, horas e minutos.

5)Função estacionar automáticamente
Esta função vai facilitar o utilizador porque ele só necessita de introduzir a marca do seu carro
e a matrícula, e a função vai percorrer a matriz tridimensional começando do piso 0 e
percorrer os lugares e filas, se houver um deles vazios ele introduza o carro nesse local.

6)Função para verificar o estado do lugar se é ocupado ou não:
Função que permite ao utilizador através da inserção do lugar , saber o estado o mesmo.

7)Função para imprimir todos os lugares:
Função que imprime todos os lugares , divididos por piso e filas e imprime o seu estado.

8)Função para imprimir os lugares livres:
Função que percorre a matriz tridimensional e imprime no ecrã os lugares que estão livres
para o utilizador estacionar.

9)Função para imprimir os lugares ocupados:
Função que percorre a matriz tridimensional e imprime no ecrã os lugares que estão livres
para o utilizador estacionar

10)Função para imprimir as informações do programa :
Função que imprime as informações que ajudam o utilizador a utilizar o programa de forma
simples e sem cometer erros.

11)Função para procurar um carro por a matricula:
Função que permite ao utilizador através da matricula do carro, encontrar o lugar onde o carro
está estacionado

12)Função para remover o carro:
Função que remove o carro do lugar , pondo o estado do lugar livre, e também calcula o custo
que o utilizador tem de pagar, este só consegue remover o carro quando a divida for saldada.

5. Conclusão
O relatório foi desenvolvido ao mesmo tempo que o projecto. O projecto está totalmente
comentado para fácil entendimento.
Ao longo destes últimos meses, inserimos novas funcionalidades no projecto, mas encontramos
uns pequenos problemas, mas que foram resolvidos o mais rápido possível. Resumindo com
este projecto ficamos a perceber bem o funcionamento de um parque de estacionamento, e
conseguimos desenvolver um projeto funcional , prático e simples para o utilizador.

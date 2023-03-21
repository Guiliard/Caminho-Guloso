<h1 align="center"> Caminho-Guloso </h1>
<br><div align=center>
<img src="https://user-images.githubusercontent.com/127882640/226417972-cf63390e-890e-447b-97fc-6859041b1581.png" width="850px">
</div>

# Introdução
<p>Foi proposto um problema de caminhamento de matrizes quadradas (NxN) de forma gulosa, ou seja, aquele que opta por um caminho específico e não há a possibilidade de retorno. Nesse problema, o caminho a ser escolhido limita-se entre 5 direções (Oeste, Sudoeste, Sul, Sudeste, Leste), e, também, para a direção que possui o maior valor. </p>

# Descrição do problema
<p>Em um arquivo do tipo ".data", localiza-se um determinado número de matrizes quadradas, as quais possuem inteiros positivos e devem ser escaneadas e transferidas para um código, o qual possui como objetivo realizar o caminhamento.<br>
Esse caminhamento das matrizes se inicia ou na posição linha 0 e coluna 0, ou na posição que o usuário escolher. A partir disso, todas as posições devem ser verificadas para que o marcador de posição avance para o maior valor que se encontra nas 5 direções possíveis e, além disso, a uma casa de distância da posição atual. Feito isso, o processo continua até que o marcador chegue na posição linha N e coluna N, ou seja, na posição final da matriz. Tendo atingido o objetivo, o programa se encerra e o somatório dos valores percorridos deve ser mostrado.</p>

# Solução proposta
<p>Para esse tipo de problema, foi proposto um código que contém 3 arquivos: Matriz.hpp, Matriz.cpp e Main.cpp.<br>

- Matriz.hpp: Possui uma classe, que retém  a declaração de variáveis e funções envolvidas no processo. <br>
- Matriz.cpp: Possui a declaração das funções. <br>
- Main.cpp: Arquivo mais importante, responsável por chamar as funções envolvidas e realizar o processo.<br>

No arquivo Matriz.cpp, duas funções foram declaradas: uma responsável por ler a matriz do arquivo ".data" e transferir-lá para o código e outra responsável por realizar o caminhamento. Nessa última função, o usuário pode escolher a posição de início. Vale ressaltar, também, que tal caminhamento foi feito através de uma ordem de prioridade, obedecendo a seguinte hierarquia: 

- Leste
- Oeste
- Sul
- Sudeste
- Sudoeste

<div align=center>
<img src="https://user-images.githubusercontent.com/127882640/226614863-49e7a6cb-5119-4769-87a1-3d0b2adc37aa.png" width="650px">
</div>

<br>Quando uma posição é avançada, o marcador substitui o valor daquela posição, transformando o número que ali se encontrava em "-1". Antes dessa transformação, o valor da posição é armazenada em uma variável, para que, assim, seja dado o total do caminho percorrido.<br>
<div align=center>
<img src="https://user-images.githubusercontent.com/127882640/226620540-31e20890-7e0a-42e9-926e-c052b7b1a755.png" hspace="50px" width="420px"/>
<img src="https://user-images.githubusercontent.com/127882640/226620658-2fbf5e03-eb0d-4b86-981a-8e36e77b9233.png" width="420px"/>
</div>

# Casos Especiais

Tendo em vista que o algorítmo é guloso, é que os caminhamentos feitos anteriormente são irretornáveis, quando o marcador atinge ou a linha N ou a coluna N, o caminhamento é realizado em uma só direção (em linha reta), ou seja, quando essa condição acontece, a prioridade de movimento é alterada.<br><br>
Caso se tenha atingido a linha N:<br>

- Somente Leste

Caso se tenha atingido a coluna N:<br>

- Somente Sul

Tal movimentação continua até que a linha N e a Coluna N da matriz (NxN) seja atingida.
<br>Esse processo é realizado com todas as matrizes do arquivo ".data". É importante salientar que esse arquivo também possuí o tamanho da matriz definido.

# Implementação 

Considere a seguinte matriz (7x7) como teste do problema proposto:
<div align=center>
<img src="https://user-images.githubusercontent.com/127882640/226637423-a8903ee5-a625-44d8-822d-e18f76b982c5.png" width="400px">
</div>
O resultado esperado é:<br>
<br><div align=center>
<img src="https://user-images.githubusercontent.com/127882640/226643911-338c30e3-62b4-40d3-90f8-ac45a4ed6a84.png" width="850px">
</div>

# Compilação e Execução

Um arquivo Makefile que realiza todo o procedimento de compilação e execução está disponível no código. Para utilizá-lo, siga as diretrizes de execução no terminal:


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |

# Modelo epidemiológicos / Epidemic model
Projeto final da disciplina de Introdução as técnicas de programação. 

/ 

Final project of the discipline Introduction to Programming Techniques.

## Autores / Authors
- [Enzo Lopes D'anjour de Souza](https://github.com/enzodanjour)
- [João Gabriel Trindade Barreto da Silva](https://github.com/JGabrielt)

### Checkpoints
#### Checkpoint 1
- [x] Implementação do modelo com entrada e saída no terminal.
- [x] Formato de dados do arquivo csv de configuração e leitura do arquivo de configuração.
- [x] Saída de dados no arquivo de csv (+25% do checkpoint).

#### Checkpoint 2
- [x] Implementação dos cenários de simulação e formato de dados do arquivo txt
de configuração e leitura do arquivo de configuração.
- [x] Plotagem dos gráficos dos três cenários em função do arquivo de entrada.
- [x] Entrega das modificações sugeridas no CP1.

### Propósito / Purpose
São utilizados para a compreensão da dinâmica de uma epidemia ou afim, e são,portanto,ferramentas essenciais na determinação de políticas públicas para combate e prevenção de doenças 

/ 

They are used to understand the dynamics of an epidemic or the like, and are therefore essential tools in determining public policies for combating and preventing diseases

### Modo de Uso / Way of using
Primeiro de tudo, devemos compilar os arquivos que serão utilizados, para isso rode no terminal o comando.

/


First of all, we must compile the files that will be used, for that run the command in the terminal.

`` 
make all
``

O próximo passo é executar o binário fruto da compilação.

/ 


The next step is to run the compilation binary.

`` 
./epidemic
``

### Como escrever um modelo para entrada de dados / How write a model to input data

Para fazer isso precisamos entrar com um arquivo .csv passando como parâmetros, respectivamente:

/

To do this we need to enter a .csv file passing as parameters, respectively:

S= Quantidade de indivíduos suscetíveis

I= Numero de indivíduos infectados

R= Número de indivíduos com imunidade ou faleceram.

h= intervalo de tempo em horas.

N= Quantidade de indivíduos infectados.

T= Intervalo de tempo.

S0= número de pessoas suscetíveis no início da observação

I0= número de pessoas infectadas no início da observação.

m= Quantos indivíduos se recuperaram.

n= Quantos indivíduos se contaminaram de um total.

T'= Intervalo de tempo para parâmetro k.

/

S = Number of susceptible individuals

I = Number of infected individuals

R = Number of individuals with immunity or who died.

h = time interval in hours.

N = Number of infected individuals.

T = Time interval.

S0 = number of susceptible people at the beginning of the observation

I0 = number of people infected at the beginning of the observation.

m = How many individuals have recovered.

n = How many individuals have been contaminated out of a total.

T '= Time interval for parameter k.


Exemplo / Example:

68,2,0,0.1,12,24,50,10,6,22,24,21 

and generate a file saida.csv


### Como plotar gráficos / Plotting Charts

Use o script em Modelo_plotagem.ipynb.

Use script in Modelo_plotagem.ipynb to ploting the charts.

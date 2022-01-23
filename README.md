<h1> Análise de Algorítmos _ Karatsuba e Método direto </h1>

<p> Nessa parte, foram desenvolvidos 2 modos :</p>
<li> O algoritmo para o usuário </li>
<li> O algoritmo utilizado para testes</li>

<p> No algorítmo do usuário, o usuário escolhe os graus dos polinômios e seus coeficientes no algóritmo para realização dos experimentos, os graus são previamente determinados pela
forma n-1 = 2**(k-1), sendo k variando entre 1, 15. Cada modo foi desenvolvido para os 2 métodos estudados e para rodá-lo, abra o diretório de sua preferência (
'AlgoritmoUsuario' ou 'AlgoritmosExperimentos') e rode os comandos abaixo:</p>
<h3> Para o Karatsuba: </h3>
<li> gcc karatsuba.c polinomio.c polinomio.h -o executavelKaratsuba.exe </li>
<li> ./executavelKaratsuba.exe </li>

<h3> Para o método direto </h3>
<li> gcc mult_direta.c polinomio.c polinomio.h -o executavelDireto.exe </li>
<li> ./executavelDireto </li>



<h1> Gráficos </h1>
<p> Antes de começar, é preciso ter instalado em sua máquina as seguintes ferramentas: </p>

<li>Python 3</li>
<p>Instale o python 3 e se for preciso torne o python e gerenciador de de pacotes pip variaveis de ambiente intalar o python na maioria das vezes o sistema operacional ja o torna variavel de ambiente logo este passo pode ser pulado.</p>

<p> Abra o diretorio do programa, onde está o codigo fonte, inicialize o terminal nesse diretorio.</p>

<p> Execute no terminal os seguintes comandos para importar as bibliotecas utilizadas no projeto : </p>

<li>pip install matplotlib</li>
<li>pip install plotly</li>
<p> Execute o código. Os gráficos serão gerados com ids de 1 a 6, na forma de um png.</p>


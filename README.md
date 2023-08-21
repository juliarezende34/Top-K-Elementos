<h1 align="center" font-size="200em"><b>Top K elementos - Análise textual</b></h1>

<div align = "center" >

[![requirement](https://img.shields.io/badge/IDE-Visual%20Studio%20Code-informational)](https://code.visualstudio.com/docs/?dv=linux64_deb)
![Make](https://img.shields.io/badge/Compilacao-Make-orange)
![Linguagem](https://img.shields.io/badge/Linguagem-C%2B%2B-blue)
</div>

## Introdução
<p align="justify">
Este é um programa desenvolvido em C++ para a disciplina de Algoritmos e Estruturas de Dados II. 
Um exemplo clássico de problema que pode ser solucionado utilizando-se hash e heap é o chamado top k itens. Neste problema, é preciso encontrar os k itens mais valiosos e uma coleção de dados. Logo, utiliza-se o hash para contar a frequência de todos os itens, enquanto o heap se aplica na manutenção de uma lista dos k itens de maior valor.
</p>

## Objetivos
<p align="justify">
O objetivo desse trabalho é encontrar as palavras mais frequentes num conjunto de textos, utilizando as estruturas tabela de dispersão (hash) e árvore de prioridades (heap). Para tal, as seguintes operações são realizadas:

- É criada uma tabela de dispersão (hash) para contar a frequência de cada elemento tokenizado da coleção de dados de entrada;
- É criada uma árvore de prioridades (heap) de tamanho k e são inseridos nela os primeiros k elementos da hash;
- Para cada elemento restante na hash, é comparada sua contagem com o menor valor do heap;
- Se a contagem for maior do que o menor valor da heap, o menor valor é removido, o novo elemento é inserido e a estrutura é refeita;
- Caso contrário, o elemento é ignorado;
- No final, a heap conterá os k elementos com maiores valores (frequências) da coleção de dados.
</p>

## Arquivos
- ```src```:
    - ```palavra.hpp```: Classe que representa cada palavra lida;
    - ```functions.hpp```: Assinatura das funções;
    - ```functions.cpp```: Implementação das funções;
    - ```main.cpp```: Leitura dos arquivos e contrução/manutenção da hash e do heap.
- ```dataset```: 
    - ```DC.txt``` e ```SMA.txt```: Bases de dados iniciais;
    - ```stopwords.txt```: Lista de stop words a serem ignoradas durante a leitura do arquivo. 

## Funções
- ```addMap```: Adiciona uma palavra em um unordered map (hash). Caso ele já esteja contido no map, o seu número de ocorrências é incrementado;
- ```isStopWord```: Verifica se a palavra está contida no unordered map que guarda as stop words a serem ignoradas;
- ```criarHeapK```: Adiciona os K primeiros elementos da hash num vector, utilizado como base para o heap;
- ```buildHeap``` e ```rebuildHeap```: Constroem o heap de acordo com a regra que os filhos do índice i são os índices (2i + 1) e (2i + 2). Se o número de ocorrências do pai for maior do que o do filho, eles trocam de lugar e chama-se a ```rebuildHeap``` novamente. Dessa forma, após a chamada da função ```buildHeap``` garante-se que o menor número está na primeira posição do vector;
- ```Swap```: Troca dois ponteiros;
- ```check```: Percorre o mapa até o fim. Caso a palavra atual tenha frequência maior do que o primeiro elemento do vector, eles trocam de lugar e o heap é refeito através da chamada de ```buildHeap```.

## Resolução do problema

## Resultados

## Conclusão

## Referências

## Compilação e execução
* Especificações da máquina em que o código foi rodado:
  * Processador Intel Core i5, 7th Gen;
  * Sistema Operacional Windows 10;
  * Terminal do WSL: Ubuntu 20.04.5;
  * 8GB de RAM.
* | Comando                |  Função                                                                                           |                     
  | -----------------------| ------------------------------------------------------------------------------------------------- |
  |  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
  |  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
  |  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |

## Contato
<div>
 <p align="justify"> Julia Rezende Gomes Rocha</p>
 <a href="https://t.me/juliarezende34">
 <img align="center" src="https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white"/> 
 </div>
<a style="color:black" href="mailto:juliarezende34@gmail.com?subject=[GitHub]%20Source%20Dynamic%20Lists">
✉️ <i>juliarezende34@gmail.com</i>
</a>
#include "functions.hpp"

int Kaux = K + 1;

void addMap(unordered_map<string, Palavra> &wordMap, string token){
    if(wordMap.find(token) != wordMap.end()){
        wordMap[token].ocorrencias++;
    }
    else{
        Palavra novaPalavra;
        novaPalavra.texto = token;
        novaPalavra.ocorrencias = 1;
        wordMap[token] = novaPalavra;
    }
}

bool isStopWord(unordered_map<string, string> &stopWordMap, string token){
    if(stopWordMap.find(token) != stopWordMap.end()){
        return true;
    }
    else{
        return false;
    }
}

void criarHeapK(unordered_map<string, Palavra> &wordMap, vector<Palavra> &vetorPalavras){
    auto iterator = wordMap.begin();
    int contador = 0;

    while(contador < K){
        //cout << iterator->second.texto << endl;
        vetorPalavras.push_back(iterator->second);
        contador++;
        iterator++;
    }
}

void Swap(Palavra *a, Palavra *b){
	Palavra aux = *a;
	*a = *b;
	*b = aux;
}

void rebuildHeap(vector<Palavra> &vetorPalavras, int i, int tamanho) {
    int filho = 2 * i + 1;
    if ((filho < tamanho - 1) && (vetorPalavras[filho].ocorrencias > vetorPalavras[filho + 1 /*Filho 2*/].ocorrencias)) {
        filho++;
    }
    if ((filho < tamanho) && (vetorPalavras[i].ocorrencias > vetorPalavras[filho].ocorrencias)) {
        swap(vetorPalavras[i], vetorPalavras[filho]);
        rebuildHeap(vetorPalavras, filho, tamanho);
    }
}

void buildHeap(vector<Palavra> &vetorPalavras) {
    int tamanho = vetorPalavras.size();
    for (int i = tamanho / 2 - 1 /*Definição do pai*/; i >= 0; i--) {
        rebuildHeap(vetorPalavras, i, tamanho);
    }
}

void check(unordered_map<string, Palavra> &wordMap, vector<Palavra> &vetorPalavras){
    auto iterator = wordMap.begin();
    int contador = 0;

    while(contador <= Kaux){
        contador++;
        iterator++;
    }
    while(iterator != wordMap.end()){
        if(iterator->second.ocorrencias > vetorPalavras[0].ocorrencias){
            Swap(&vetorPalavras[0], &iterator->second);
            buildHeap(vetorPalavras);
        }
        iterator++;
    }
}
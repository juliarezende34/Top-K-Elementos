#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "palavra.hpp"

void addMap(unordered_map<string, Palavra> &wordMap, string token);//
bool isStopWord(unordered_map<string, string> &stopWordMap, string token);//
void criarHeapK(unordered_map<string, Palavra> &wordMap, vector<Palavra> &vetorPalavras);//
void buildHeap(vector<Palavra> &vetorPalavras);
void rebuildHeap(vector<Palavra> &vetorPalavras, int i, int size);//
void Swap(Palavra *a, Palavra *b);
void check(unordered_map<string, Palavra> &wordMap, vector<Palavra> &vetorPalavras);

#endif
#include "palavra.hpp"
#include "functions.hpp"
#include <fstream>
#include <sstream> 
#include <vector>
#include <time.h>
#define NUMERO_ARQUIVOS 2

int main() {
    clock_t startTime, endTime;
    startTime = clock();

    string vetorArquivos[NUMERO_ARQUIVOS] = {"dataset/DC.txt", "dataset/SMA.txt"}, linha;
    ifstream arquivo, arquivoStopWords;
    vector<string> tokens;
    vector<Palavra> vetorPalavras;
    string token, stopword; 
    unordered_map<string, Palavra> wordMap;
    unordered_map<string, string> stopWordMap;

    arquivoStopWords.open("dataset/stopwords.txt", ios::in);
    while(!arquivoStopWords.eof()){
        arquivoStopWords >> stopword;
        stopWordMap[stopword] = stopword;
    }
    arquivoStopWords.close();

    for(int i = 0; i < NUMERO_ARQUIVOS; i++){

        arquivo.open(vetorArquivos[i], ios::in);

        if (!arquivo.is_open()) {
            cout << "Não foi possível abrir o arquivo." << endl;
            return 1;
        }

        while (getline(arquivo, linha)) {
            linha.erase(remove(linha.begin(), linha.end(), ','), linha.end());
            linha.erase(remove(linha.begin(), linha.end(), '.'), linha.end());
            linha.erase(remove(linha.begin(), linha.end(), '?'), linha.end());
            linha.erase(remove(linha.begin(), linha.end(), '!'), linha.end());
            linha.erase(remove(linha.begin(), linha.end(), '"'), linha.end());
            linha.erase(remove(linha.begin(), linha.end(), ';'), linha.end());
            linha.erase(remove(linha.begin(), linha.end(), '/'), linha.end());
            linha.erase(remove(linha.begin(), linha.end(), ':'), linha.end());

            istringstream iss(linha); 

            while (iss >> token) {
                if ((token != "--") && (token != "—") && (token != "“") && (token != "”")) { 
                    if (token.size() > 2 && token.substr(0, 2) == "--") {
                        token = token.substr(2); // Remove os primeiros dois caracteres "--", para quando não há espaço
                    }
                    transform(token.begin(), token.end(), token.begin(), ::tolower);
                    if(!isStopWord(stopWordMap, token)){
                        addMap(wordMap, token);
                    }
                }
            }
        }
        arquivo.close();
    }

    criarHeapK(wordMap, vetorPalavras);
    check(wordMap, vetorPalavras);

    for(int i = 0; i < (int)vetorPalavras.size(); i++){
        if(i <= 8){
            cout << i+1 << "  | " << vetorPalavras[i].ocorrencias << " | " << vetorPalavras[i].texto << endl;
        }
        else{
            cout << i+1 << " | " << vetorPalavras[i].ocorrencias << " | " << vetorPalavras[i].texto << endl;
        }
    }
    cout << endl;

    endTime = clock();
    clock_t elapsedTime = endTime - startTime;
    double elapsedTimeMs = ((double)elapsedTime/CLOCKS_PER_SEC)*1000;
    cout << "TEMPO DE EXECUÇÃO: " << elapsedTimeMs << " ms " << endl;
    
    return 0;
}
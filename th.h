#ifndef TH_H_INCLUDED
#define TH_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

const int TAM = 8;

struct tabela {
    char estado;
    string chave;
};

void inicializarTabela(tabela tab[]) {
    for (int i = 0; i < TAM; i++)
        tab[i].estado = 'L'; // L de livre
}

int funcaoDeHashing(int chave) {
    return chave % TAM;
}

int funcaoDeHashingString(const string& str) {
    int hash = 0;
    int base = 31; // Um número primo comum usado em hashing
    for (char ch : str) {
        hash = (base * hash + ch) % TAM;
    }
    return hash;
}

void inserir(tabela tab[], const string& chave) {
    int posicao = funcaoDeHashingString(chave);
    int inicial = posicao;

    while (tab[posicao].estado == 'O') {
        posicao = (posicao + 1) % TAM;
        if (inicial == posicao) {
            cout << endl << "A lista está cheia! Impossível inserir o " << chave << endl;
            return;
        }
    }

    tab[posicao].chave = chave;
    tab[posicao].estado = 'O';
}

int buscarElemento(tabela tab[], const string& chaveDeBusca) {
    int posicao = funcaoDeHashingString(chaveDeBusca);

    while (tab[posicao].estado != 'L') {
        if (tab[posicao].chave == chaveDeBusca)
            return posicao;
        else
            posicao = (posicao + 1) % TAM;
    }

    return -1;
}

void remover(tabela tab[], const string& chaveDeBusca) {
    int posicao = buscarElemento(tab, chaveDeBusca);
    if (posicao == -1)
        cout << "Posição não localizada!";
    else
        tab[posicao].estado = 'L';
}

void imprimir(tabela tab[]) {
    cout << endl << endl;
    cout << "Tabela hashing imprimindo..." << endl;
    for (int i = 0; i < TAM; i++) {
        if (tab[i].estado == 'L')
            cout << "Posição " << i << " - Livre" << endl;
        else
            cout << "Posição " << i << " - " << tab[i].chave << endl;
    }
}

#endif // TH_H_INCLUDED

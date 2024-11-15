#include <iostream>
#include <string>
using namespace std;

#include "th.h"

int main() {
    tabela tabela_h[TAM];
    inicializarTabela(tabela_h);

    struct filme {
       string nome: "teste",
       bool alugado: false;
    };

    inserir(tabela_h, filme);

    imprimir(tabela_h);
    return 0;
}

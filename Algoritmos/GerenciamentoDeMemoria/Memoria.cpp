#include <iostream>
using namespace std;

int x;      // variaveis globais não inicializada
int y = 15; // variaveis globais

int main(){
    int *values; // valores na pila de dados locais
    int i;

    values = new int[5]; // valor na heap => espaço dinamicamente alocado;
    // new[x]=> aloca x espaços de 4bytes na memória
    // delete => libera memoria
    // delete[] => libera memoria (array)

    for(i=0; i<5 ; i++){
        values[i] = i;
    }

    free(values);
    return 0;
}
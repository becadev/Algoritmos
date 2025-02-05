#include <iostream>
using namespace std;

// QUESTAO B - posição do maior elemento
/*int maior_array(int a[], unsigned int n) {
    int resultado = a[0];
    int posicao = 0;
    for (unsigned int i = 1; i < n; ++i) {
        if (a[i] > resultado) {
        resultado = a[i];
        posicao = i;
        }
    }
    return posicao;
} 
*/
// QUESTAO C - menor elemento
int maior_array(int a[], unsigned int n) {
    int resultado = a[0];
    for (unsigned int i = 1; i < n; ++i) {
        if (a[i] < resultado) {
        resultado = a[i];
        }
    }
    return resultado;
} 
int main() {
    unsigned int n; // unsigned - sem sinal, uma array não pode ter tamanho negativo. 
    std::cin >> n;
    int a[n];
        for (unsigned int i = 0; i < n; ++i) {
        std::cin >> a[i];
        }
    int maior = maior_array(a, n);
    std::cout << maior << std::endl;
    return 0;
}

/*
Um unsigned int pode representar o dobro do intervalo positivo de um int normal, 
então se fosse necessário um valor de tamanho grande,
unsigned aumentaria a capacidade sem usar mais memória.
*/
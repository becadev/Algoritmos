#include <iostream> //contém definições de diversas funções e classes (por exemplo, cout e cin) 
using namespace std;
#define PRECO 1.99 
//A linha #define PRECO 1.99 no início do programa define uma macro. Ou seja, definimos que
//PRECO é um sinônimo para 1.99 e, portanto, toda ocorrência de PRECO no programa é substituído por
//1.99 antes que ele seja compilado.


// definição de constantes
// funções

int main(){ //main é uma função que marca o ponto de iníciode execução do programa.
    // declaração de variáveis
    // sentenças
    int pera; //declaração da variável
    char qualidade;  //declaração da variável
    float peso;  //declaração da variável
    pera = 3;
    qualidade = 'A';
    peso = 0.653;
    cout << pera << endl; // cout: print, endl representa quebra de linha
    cout << "Existem " << pera << "peras de qualidade " << qualidade<< "pesando " << peso << "quilos." << endl;
    cout << "O preco por quilo eh R$" << PRECO << ", o total eh R$" << peso * PRECO << endl;
}

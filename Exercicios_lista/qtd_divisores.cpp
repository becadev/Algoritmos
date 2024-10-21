/*
Escreva um programa leia um número natural positivo n (1 ≤ n ≤ 109

) e mostre a quantidade de divisores de n.

• Determine o tipo da variável que deve armaenar n.
• Escreva uma função que receba n e retorne a quantidade de divisores.
• Faça testes e verifique se seu programa funciona corretamente.

*/
# include <iostream>
using namespace std;

int divisores(int n, int qtd){
    for (int i = 1 ; i > n ; i++){
        if (n % i == 0){
            qtd += 1;
            std::cout << i << std :: endl;
        }
    }
    return qtd;
}

int main(){
    int n,qtd_div = 0;
    std::cin >> n;
    qtd_div = divisores(n,qtd_div);
    std::cout << qtd_div << std::endl;
    return 0;
}
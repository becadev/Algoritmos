/* MDC de dois inteiros positivos por meio do algoritmo de Euclides*/

# include <iostream>
using namespace std;

int MDC(int a,int b){
    int maior,menor,aux;
    if (a<b){
        maior = b;
        menor = a;
    }else{
        maior = a;
        menor = b;
    }
    while (maior!=menor){
        aux = maior;
        maior = menor;
        menor = aux - menor;
    }
    return maior;
}
int main(){
    int a, b, mdc;
    std::cin >> a >> b;
    mdc = MDC(a,b);
    std:: cout << mdc << std:: endl;
    return 0;
}

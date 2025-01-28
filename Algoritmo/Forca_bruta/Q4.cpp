# include <iostream>
# include <algorithm>
using namespace std;

int soma (int num[], int soma_array){
    int maior = soma_array;
    int menor = 0;
    int resultado = 0;

    for (int i = 0 ; i < 9 ; i++){
        menor = num[i];
        for (int k = i ; k < 8 ; k++){
            menor += num[k];
        }
        if (menor > maior){
            maior = menor;
        }
        if (resultado < maior)
            resultado = maior;
    }
    return resultado;
}

int main(){
    int num[9];
    int soma_array = 0;
    for (int i = 0 ; i < 9 ; i++){
        std:: cin >> num[i];
        soma_array += num[i];
    }
    int maior_soma = soma(num, soma_array);
    std:: cout << maior_soma << std :: endl;

    return 0;
}
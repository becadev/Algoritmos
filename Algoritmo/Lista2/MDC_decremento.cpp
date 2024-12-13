# include <iostream>
using namespace std;

int main(){
    int mdc, maior, menor, aux;
    std::cin >> maior >> menor;
    if (menor > maior){
        aux = maior;
        maior = menor;
        menor = aux;
    } 
    for (int i = menor ; menor > 1 ; i--){
        if ((maior % i == 0) and (menor % i == 0)){
            mdc = i;
            break;
        }
    }
    std:: cout << mdc << std:: endl;
    return 0;
}
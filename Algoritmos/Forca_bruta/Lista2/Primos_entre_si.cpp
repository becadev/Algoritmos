/*
Sejam a e b dois números naturais positivos, 
eles são considerados primos entre sí se não possuírem divisores em
comum além do número 1 (um). A seguir um algoritmo para determinar 
se dois números são primos entre sí:
*/
# include <iostream>
using namespace std;

int main(){
    int a, b, n;
    std::cin >> a >> b;
    bool primo = true;
    if (a<b){
        n = b;
    }else{
        n = a;
    }
    for (int i = 2 ; i < n; i++){
        if ((a % i == 0) && (b % i == 0)){
            primo = false;
            break;
        }
    }
    std::cout << primo << std::endl;
    return 0;
}
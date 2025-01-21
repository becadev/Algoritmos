#include <iostream>
using namespace std;

int main(){
    int a = 20;
    int *p;
    p = &a;
    cout << " O valor de  a:"  << a  << endl;
    cout << " Endereço de a:"  << &a << endl; // &var = mostra o endereço na memoria em hexadecimal
    cout << " Valor de *p:  "  <<*p << endl; // mostra o valor do endereço que ele está guardando
    *p = 50;                                // coloca esse valor na variavel em que ele está apontando
    cout << " Valor de a:   "  << a << endl;  
    return 0;
}


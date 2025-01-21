# include <iostream>
using namespace std;

int main(){
    int i, a[5];
    int *p;
    for (i=0 ; i<5 ; i++){
        a[i] = 2*i;
    }
    p = a;  // vai apontar para o primeiro endereço da array
    for(i=0 ; i<5 ; i++){
        cout << *p << endl;
        p++;        // vai andar na fila.
    }
    return 0;
}
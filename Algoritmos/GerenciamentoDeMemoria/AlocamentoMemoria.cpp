#include <iostream>
using namespace std;

int main(){
    int *n, t, i;
    cin >> t;
    n = new int[t]; // alocamento de memória, alocando um espaço t na memória
    if (n == nullptr){ // se o valor for nulo
        cerr << "ERRO ao alocar memória" << endl;
        exit(1);
    }
    // ##################### Uso da memoria alocada
    for(i=0 ; i<t ; i++)
        cin >> n[i];
    for(i=0 ; i<t ; i++){
        cout << n[i] << " ";
    }
    // ####################
    cout << endl;
    delete [] n; // libera memória, sempre tem que liberar a memória alocada;
    return 0;
}
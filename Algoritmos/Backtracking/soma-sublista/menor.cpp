#include <iostream>
# include <algorithm>
using namespace std;
// condition ? A : B
int soma_sublista_bt(int *a, int tam, int soma, int cont){
    if(soma == 0) return cont; // caso veridico
    if(soma < 0 || (tam == 0 and soma > 0)) return 1000 ; // rejeita
    int r1 = soma_sublista_bt(a, tam-1, soma-a[tam-1], cont + 1); // se isso aqui não for veridico
    int r2 = soma_sublista_bt(a, tam-1, soma, cont); // ent ele volta para celula que tava e tenta outro numero que encaixe na soma
    return min({r1,r2});
}
int soma_sublista(int *a, int tam, int soma){
    int x = soma_sublista_bt(a,tam,soma, 0);
    if (x >= 1000) return 0;
    return x;
}

int main(){
    int * a, n, s, i;
    cin >> n >> s;
    a = new int[n];
    for(i = 0 ; i<n ; i++)
        cin >> a[i];
    cout << soma_sublista(a,n,s) << endl;
    delete a;
    return 0;
}
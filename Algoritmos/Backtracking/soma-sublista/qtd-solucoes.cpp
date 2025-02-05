#include <iostream>
# include <algorithm>
using namespace std;
// condition ? A : B
int soma_sublista_bt(int *a, int tam, int soma){
    if(soma ==0) return 1; // caso veridico
    if(soma < 0 || tam ==0) return 0; // rejeita
    int r1 = soma_sublista_bt(a, tam-1,soma-a[tam-1]);
    int r2 = soma_sublista_bt(a, tam-1, soma);
    // int menor = min({r1,r2});
    return r1+r2;
}
int main(){
    int * a, n, s, i;
    cin >> n >> s;
    a = new int[n];
    for(i = 0 ; i<n ; i++)
        cin >> a[i];
    cout << soma_sublista_bt(a,n,s) << endl;
    delete a;
    return 0;
}
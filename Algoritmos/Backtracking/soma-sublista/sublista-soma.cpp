#include <iostream>
using namespace std;

bool soma_sublista_bt(int* a, int tam, int soma){
    int r;
    if(soma == 0 ) // aceita pq chegou ao final do valor
        return true;
    if(soma < 0 || tam == 0) // rejeita 
        return false;
    r = soma_sublista_bt(a,tam - 1, soma - a[tam-1]);
    r = r || soma_sublista_bt(a, tam-1, soma);
    return r;
}

int main(){
    int *a, n, s,i;
    cin >> n >> s;
    a = new int[n];
    for (i = 0 ; i < n ; i++ )
        cin >> a[i];
    if(soma_sublista_bt(a,n,s))
        cout<< 1 << endl;
    else   
        cout << 0 << endl;
    delete a;
    return 0;
}
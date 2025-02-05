#include <iostream>
#include <vector>
using namespace std;

struct resposta{ // cria uma estrutura para retorna se existe e a sublista
    bool existe;
    vector<int> sublista;
};
resposta soma_sublista_bt(int *a, int tam, int soma){ // verifica se a sublista existe e retorna os elementos dela
    if(soma == 0)return {true, {}}; // verifica se a soma realmente existe
    if(soma<0 || tam == 0) return {false,{}}; 
    resposta ans = soma_sublista_bt(a, tam-1, soma - a[tam-1]); // faz a chamada com o valor da soma e o elemento antecesor do atual da chamada
    if(ans.existe) // se existe ent adiciona o elemento na sublista
        ans.sublista.push_back(a[tam-1]);
    else 
        ans = soma_sublista_bt(a, tam-1, soma); // se não, realiza outra chamada só que apartir do elemento antecessor ao que começou as somas anterior, ex: se antes começou no 12 da lista (8,35,6,21,12), agr irá começar no 21
    return ans;
}

int main(){
    int *a, n, s, i;
    cin >> n >> s;
    a = new int[n];
    for(i = 0 ; i < n ; i++)
        cin >> a[i];
    resposta ans = soma_sublista_bt(a,n,s);
    if(ans.existe){
        cout << "Existe sublista de soma " << s << endl;
        for(unsigned int i = 0 ; i< ans.sublista.size() ; i++)
            cout << ans.sublista[i] << " ";
    }
    else    
        cout << "Não existe sublista de soma" << s << endl;
        cout<<endl;
        delete [] a;
        return 0;
}
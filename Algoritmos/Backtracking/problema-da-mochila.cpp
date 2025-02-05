# include <iostream>
# include <vector>
using namespace std;

struct item{
    int peso;
    double valor;
};
double mochila(vector<item> & itens, int q, int peso){
    int ans = 0;
    if(peso < 0) return 0;
    if(peso == 0) return 1;
    

    return ans;
} // retorna qual o maior valor

int main(){
    int n, peso_maximo;
    cin >> n >> peso_maximo;
    vector<item>itens(n);
    for(item & i : itens)
        cin >> i.peso >> i.valor;
    double valor = mochila(itens, n-1, peso_maximo);
    return 0;
}

// Qual valor máximo que posso colocar na mochila
/*Caso Teste
A = 7 42.0
B = 3 12.0
C = 4 40.0
d = 5 25.0
*/
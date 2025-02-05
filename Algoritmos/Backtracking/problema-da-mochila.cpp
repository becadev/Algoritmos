# include <iostream>
# include <vector>
# include <algorithm>
# include <iomanip>
using namespace std;

struct item{
    int peso;
    double valor;
};
// q = qtd de itens
double mochila_r(vector<item> & itens, int q, int peso, double v){
    if(peso < 0 || q < 0) return 0.00;
    if(q == 0) return v;
    double r1 = mochila_r(itens, q-1, peso - itens[q-1].peso, v + itens[q-1].valor);
    double r2 = mochila_r(itens, q-1, peso, v);
    return max({r1,r2});
} // retorna qual o maior valor

double mochila(vector<item> & itens, int q, int peso){
    double valor = mochila_r(itens, q, peso, 0.00);
    return valor;
}

int main(){
    int n, peso_maximo;
    cin >> n >> peso_maximo;
    vector<item>itens(n);
    for(item & i : itens)
        cin >> i.peso >> i.valor;
    double valor = mochila(itens, n, peso_maximo);
    cout << fixed << setprecision(2) << valor << endl;
    return 0;
}

// Qual valor máximo que posso colocar na mochila
/*Caso Teste
A = 7 42.0
B = 3 12.0
C = 4 40.0
d = 5 25.0
*/
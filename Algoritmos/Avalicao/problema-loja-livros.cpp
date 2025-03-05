/* Problema da loja de livros: Considere uma loja com N livros a venda. Cada livro i possui um preço de venda pi e uma quantidade de páginas qi.
Um cliente, com orçamento fixo X decide comprar a maior quantidade de páginas possível com esse valor. */
#include <bits/stdc++.h>
using namespace std;
int INF = 10000000;
std::vector<std::vector<int>> dp;
/* Exemplo:
Ex1 Entrada:
N = 3  quantidade de livros disponíveis para venda
X = 15  valor para comprar livros
Livros:  
Preço: [5, 3, 7]  
Páginas: [60, 40, 90] 

Saída: 190 páginas

Ex2 Entrada:
N = 4  
X = 12  
Livros:  
Preço: [8, 5, 12, 7]  
Páginas: [100, 80, 150, 90]  
saída: 170

N = 3  
X = 2  
Livros:  
Preço: [5, 8, 4]  
Páginas: [30, 50, 20]  
saída: 0
*/

int paginas_bt(std::vector<int> & p, std::vector<int> & pag, int n, int v, int paginas){ // Solução copm backtracking
    if(v == 0) return paginas;
    if(v < 0 || n < 0) return 0;
    int p1 = paginas_bt(p, pag, n-1, v - p[n], paginas + pag[n]);
    int p2 = paginas_bt(p, pag, n-1, v , paginas);
    return max(p1,p2);
}

int pag_pd(std::vector<int> & p, std::vector<int> & pag, int n, int v, int paginas){ // Solução com programação dinâmica
    if(v < 0 || n < 0) return 0;
    if(dp[v] != -1) return dp[v];
    if(v == 0) return paginas;
    int p1 = paginas_bt(p, pag, n-1, v - p[n], paginas + pag[n]);
    int p2 = paginas_bt(p, pag, n-1, v , paginas);
    return dp[v] = max(p1,p2);
}


int main(){
    int n, v;
    cin >> n >> v;
    std::vector<int> p(n);
    std::vector<int> pag(n);
    dp.resize(n, std::vector<int>(n+10, -1));
    for(int i = 0 ; i < n ; i ++)
        cin >> p[i];
    for(int i = 0 ; i < n ; i ++)
        cin >> pag[i];

    // cout << paginas_bt(p, pag, n-1, v, 0) << endl;
    cout << pag_pd(p, pag, n-1, v, 0) << endl;
    return 0;
}
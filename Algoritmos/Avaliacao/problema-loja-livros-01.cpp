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
    if(v == 0 || (n ==-1 )) return paginas;
    if(v < 0 || n < 0) return 0;
    int p1 = paginas_bt(p, pag, n-1, v - p[n-1], paginas + pag[n-1]);
    int p2 = paginas_bt(p, pag, n-1, v , paginas);
    
    return max(p1,p2);
}

int pag_pd(std::vector<int> & p, std::vector<int> & pag, int n, int v){ // Solução com programação dinâmica
    if(v == 0) return 0; 
    if(v < 0 || n < 0) return INT_MIN; // casos inválidos
    if(dp[n][v] != -1) return dp[n][v];
    
    int p1 = pag[n-1] +(pag_pd(p, pag, n-1, v - p[n-1])); // com o livro
    int p2 = pag_pd(p, pag, n-1, v); // sem o livro

    dp[n][v] = max(p1,p2); // salva na tabela

    if (dp[n][v] < 0) return 0; // caso o valor seja INT_MIN
    return dp[n][v];
}

int main(){
    using namespace std::chrono;
    int n, v;
    cin >> n >> v;
    std::vector<int> p(n);
    std::vector<int> pag(n);
    auto beg = std::chrono::high_resolution_clock::now();
    dp.resize(v+1, std::vector<int>(v+1, -1));
    for(int i = 0 ; i < n ; i ++)
        cin >> p[i];
    for(int i = 0 ; i < n ; i ++)
        cin >> pag[i];
    cout << paginas_bt(p, pag, n, v, 0) << endl;

    //cout << pag_pd(p, pag, n-1, v) << endl;
    auto end = std::chrono::high_resolution_clock::now();
    cerr << "Tempo de execução do Backtracking: " << duration_cast<milliseconds>(end - beg).count() << "ms" << endl;
    //cerr << "Tempo de execução com Programação dinâmica em segundos: " << elapsed.count() << endl;
    return 0;
}




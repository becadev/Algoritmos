#include <iostream>
using namespace std;


// Pq mesmo dando o f1 e f2 precisa manter linha e coluna na chamada? Pq pode ser que pra chegar a f1 e f2(saída) seja necessário passar por células próximas a linha e coluna, e tbm para verificar quando passa do limite

bool labirinto_bt(int labirinto[20][20], int f1, int f2, int linha , int coluna, int l, int c){
    if(c <= -1 || l <= -1 || c >= coluna || l >= linha || labirinto[l][c] != 0)
        return false;
    if(l == f1 && c== f2) // posições válidas
        return true;
    labirinto[l][c] = 9;
    bool ans = labirinto_bt(labirinto, f1, f2, linha, coluna, l, c+1) || labirinto_bt(labirinto, f1, f2, linha, coluna, l, c-1) || 
    labirinto_bt(labirinto, f1, f2, linha, coluna, l+1, c) || labirinto_bt(labirinto, f1, f2, linha, coluna, l-1, c);
    labirinto[l][c] = 0;
    return ans;
}

int main(){ // O(n²)
    int linha, coluna, inicio1, inicio2, fim1, fim2;
    cin >> linha >> coluna;
    int lab[20][20];

    cin >> inicio1  >> inicio2; // recebe as celulas iniciais
    cin >> fim1 >> fim2; // recebe as celulas finais

    for(int l = 0 ; l < linha; l++){
        for(int c = 0 ; c < coluna ; c++)
            cin >> lab[l][c];
    }
    cout  << labirinto_bt(lab, fim1, fim2, linha, coluna, inicio1, inicio2) << endl;
    return 0;
}


/*
Caso de Teste 1: Caminho Livre
Entrada:

Copiar
Editar
5 5
0 0
4 4
0 0 0 0 0
0 1 1 1 0
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
Descrição: O labirinto é 5x5 e não há barreiras que bloqueiem o caminho entre a célula inicial (0,0) e a célula final (4,4).
Resultado Esperado: Caminho possível.
Caso de Teste 2: Sem Caminho
Entrada:

Copiar
Editar
4 4
0 0
3 3
0 1 0 0
0 1 0 0
1 1 0 1
0 0 0 0
Descrição: O labirinto é 4x4, mas não há caminho livre entre a célula inicial (0,0) e a célula final (3,3) devido às barreiras.
Resultado Esperado: Sem caminho possível.
Caso de Teste 3: Labirinto com Barras
Entrada:

Copiar
Editar
5 5
0 0
4 4
0 0 1 1 0
0 0 0 1 0
1 1 0 0 0
0 0 1 1 0
0 0 0 0 0
Descrição: O labirinto é 5x5 com algumas barreiras, mas há um caminho livre entre a célula inicial (0,0) e a célula final (4,4).
Resultado Esperado: Caminho possível.
Caso de Teste 4: Barricada Completa
Entrada:

Copiar
Editar
6 6
0 0
5 5
1 1 1 1 1 1
1 0 1 1 1 1
1 0 1 1 1 1
1 0 0 0 1 1
1 1 1 0 1 1
1 1 1 0 0 0
Descrição: O labirinto é 6x6, mas há uma parede completa entre a célula inicial (0,0) e a célula final (5,5), tornando impossível alcançar o destino.
Resultado Esperado: Sem caminho possível.
Caso de Teste 5: Célula Inicial e Final na Mesma Posição
Entrada:

Copiar
Editar
5 5
2 2
2 2
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
Descrição: O labirinto é 5x5 e a célula inicial é a mesma que a célula final (2,2), então o algoritmo deve retornar que o destino é alcançado imediatamente.
Resultado Esperado: Caminho possível (imediatamente, sem movimentos necessários).
Caso de Teste 6: Labirinto com Caminho Curto
Entrada:

Copiar
Editar
3 3
0 0
2 2
0 0 0
1 1 0
0 0 0
Descrição: O labirinto é 3x3, e o caminho entre a célula inicial (0,0) e a célula final (2,2) é bem simples.
Resultado Esperado: Caminho possível.
Caso de Teste 7: Labirinto Grande, Com Múltiplos Caminhos
Entrada:

Copiar
Editar
7 7
0 0
6 6
0 0 1 1 0 0 0
0 0 1 1 0 1 0
0 0 0 0 0 1 0
1 1 1 0 1 1 0
0 0 0 0 0 0 0
1 1 1 1 0 0 0
0 0 0 0 1 0 0
Descrição: O labirinto é 7x7 e há múltiplos caminhos possíveis entre a célula inicial (0,0) e a célula final (6,6).
Resultado Esperado: Caminho possível.
Caso de Teste 8: Labirinto Com Grande Quantidade de Barreiras
Entrada:

Copiar
Editar
6 6
0 0
5 5
1 1 1 1 1 1
1 0 1 1 1 1
1 0 1 1 1 1
1 0 0 0 1 1
1 1 1 0 1 1
1 1 1 0 0 0
Descrição: O labirinto é 6x6, e o caminho entre a célula inicial (0,0) e a célula final (5,5) está bloqueado em muitas áreas.
Resultado Esperado: Sem caminho possível.*/
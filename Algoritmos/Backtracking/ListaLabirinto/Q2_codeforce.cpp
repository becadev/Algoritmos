# include <iostream> 
using namespace std;

bool verifica(int labirinto[20][20], int linha , int coluna, int l, int c){
    if(c <= -1 || l <= -1 || c >= coluna || l >= linha || labirinto[l][c] != 0)
        return false;
    if(l == linha-1 && c== coluna-1) // posições válidas
        return true;
    labirinto[l][c] = 9;
    bool ans = labirinto_bt(labirinto, linha, coluna, l, c+1) || labirinto_bt(labirinto, linha, coluna, l, c-1) || 
    labirinto_bt(labirinto, linha, coluna, l+1, c) || labirinto_bt(labirinto, linha, coluna, l-1, c);
    labirinto[l][c] = 0;
    return ans;
} 
   
int melhor_caminho(int labirinto[20][20], int linha , int coluna, int l, int c)
    if(c <= -1 || l <= -1 || c >= coluna || l >= linha || labirinto[l][c] != 0) // paredes ou células já passadas
        return 0;
    if(l == linha-1 && c== coluna-1) // chegou ao fim do labirinto
        return 1;
    if(atual >= menorcaminho){ // (2)
        return;
    labirinto[l][c] = 9;
}

/* Uai
    1) veririfca se ha um caminho valido para saida, se sim retornar a qtd de caminhos que será utilizada para criar o array
    2) percorrer os caminhos e salvar em uma array e pegar o valor minimo dos caminhos percorridos
    ?) Como que ele ia armazernar os indices? tipo,ex:  labirinto_bt(labirinto, linha, coluna, l + 1, c, index+1), o index não seria atualizado
    na chamda dentro dessa chamada? no stoy compreendendo
    
    ou 
    
    1) veririfca se ha um caminho valido para saida, se sim, entra na função de achar o menor caminho
    2) a cada chamada ir atualizando o caminho atual, 
    se o caminho atual for maior que o menor caminho encontrado já saia daquela chamada rec e ia para outra chamada
    ?) Como que ele ia retornar o atual e o menor caminho de cada e ir atualizando? sem conflitar um no outro? confusa.
    ?) 

*/


int main(){
    int linha, coluna, labirinto[20][20];
    cin >> linha >> coluna;
    for(int i = 0 ; i < linha ; i++)
        for(int j = 0 ; j < coluna ; j++)
            cin >> labirinto[i][j];
    cout << labirinto_bt(labirinto, linha, coluna, 0, 0) << endl;
    return 0;
}

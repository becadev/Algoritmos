// Fita Colorida - F1PJ - OBI 2015
// Complexidade : O(n)
# include <iostream>
# include <algorithm>
using namespace std;


// valores altos para manter a precisão do código em casos de testes com qtd altas
/* Representa uma "distância infinita", usada para inicializar os vetores de distância (esq e dir). 
Esse valor é muito maior que qualquer distância possível.*/
# define inf  999999999
/* Define o tamanho máximo da fita (vetor fita) 
como 10.100, garantindo que o programa suporte até esse número de posições.*/

# define max  10100

int main(){
    int n;
    cin >> n;
    int fita[max];
    int esq[max];
    int dir[max];

            // recebendo fita
            for (int i = 1 ; i <=n ; i++)cin >> fita[i];

            for(int i = 0 ; i <= n + 1 ; i++){
                dir[i] = esq[i] = inf;
            }   

            // olha a distancia do zero para a esquerda
            for (int i = 1 ; i <= n ; i++){
                // se o tom for zero, será zero
                if(fita[i] == 0)
                    esq[i] = 0;
                // senao, é a distancia do tom a esquerda + 1
                else esq[i] = esq[i-1] + 1;
            }


            // mesma coisa só que para a direita do zero
            for (int i = n; i > 0; i--){
                // se o tom for zero, será zero
                if(fita[i] == 0)
                    dir[i] = 0;
                // senao, é a distancia do tom a direita + 1
                else dir[i] = dir[i+1] + 1;
            }

			// printando de acordo com a distancia min.
            for (int i = 1 ; i <= n ; i++){
                cout << min(9, min(esq[i], dir[i]));
                if (i < n){
                    cout << " ";
                }
            }
            cout << endl;
}

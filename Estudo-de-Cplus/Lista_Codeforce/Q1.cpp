// Média - V Maratona Norte Mineira de Programação
// Compelixidade: O(n³)
 
# include <iostream>
# include <algorithm>
# include <iomanip>
using namespace std;

double maior_media(double a[], int n,int k){
    int qtd = (n * (n - 1) * (n - 2)) / 6;
    double resposta;
    // alocação dinâmica 
    double* medias = new double[qtd];
    int cont = 0;


    // realizando as medias
    for (int i = 0 ; i < n-2 ; i++ ){
        for (int k = i+1 ; k < n-1 ; k++){
            for (int j = k+1 ; j < n; j ++){
                medias[cont] = (a[i] + a[k] + a[j]) / 3.0;
                cont++;
            }
        }
    }
    // ordena
    std::sort(medias,  medias + cont);
    resposta = medias[cont-k];

    // libera memoria alocada;
    delete[] medias;

    return resposta;
}

int main(){
    int n, k;
    // Recebe EOF
    while(cin >> n >> k){
        double a[n];
        for (int i = 0 ; i < n ; i++){
            cin >> a[i];
        }
        std::sort(a,a+n);
        cout << fixed << setprecision(1) << maior_media(a, n, k) <<endl;
        // cout << setprecision(1) << media << endl;
    } 
    return 0;
}


/*
TESTE QUE ESTpA GERANDO SAIDA ERRADA:
4 4
1 2 3 5
saida errada: 2.0
saida certa: 3.0
*/
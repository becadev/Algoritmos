# include <iostream>
# include <algorithm>
# include <iomanip>
# include <set>
using namespace std;
// Ordenar 

int fatorial(int nk){
    int fat = 1;
    for (int i = 2 ; i <= nk ; i++){
        fat *= i;
    }
    return fat;
}

double maior_media(double a[], int n,int k){
    int n_fat = fatorial(n);
    int k_fat = fatorial(k);
    int qtd = (n_fat) / ((k_fat)* fatorial(n-k));
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
    // ordena e elimina elementos repetidos e colocar dentro de um set
    std::sort(medias,  medias+qtd);
    set<double> lista(medias, medias + qtd);
    delete[] medias; // libera memoria alocada;

    // verifica o tamanho do set após retirar os repetidos
    int tamanho = lista.size();

    cont = 0;
    double* array_medias = new double[tamanho];

    // colocando os elementos do set dentro da array
    for (auto elem :lista){
        
        array_medias[cont] = elem; 
        cont++;
    }

    int i = tamanho;
    cont = 0;

    while (i > 0){
        i--;
        if (array_medias[i] > array_medias[i-1]){
            cont ++;
        }
        if (cont == k){
            resposta = array_medias[i];
            break;
        }
    }

    // libera memoria alocada;
    delete[] array_medias;

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
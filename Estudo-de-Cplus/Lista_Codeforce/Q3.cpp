# include <iostream>
# include <iomanip>
# include <algorithm>
# include <sstream> // Para std::istringstream
using namespace std;




int tamanho_do_esforco(int lista[], int m){
    int tamanho = m;
    int qtd_subida = 0;
    int qtd_descida = 0;
    int dif_medicoes_ida = 0;
    int dif_medicoes_volta = 0;
    int esforco = 0;

    for (int i = 1 ; i < tamanho ; i++){
        if (lista[i] > lista[i-1]){
            qtd_subida+=1;
            dif_medicoes_ida += lista[i] - lista[i-1];
        }
        if (lista[i] < lista[i-1]){
            qtd_descida+=1;
            dif_medicoes_volta += lista[i] - lista[i-1];
        }
    }

    if ((qtd_descida == tamanho) || (qtd_subida == tamanho)){
        esforco = 0;
    }
    else if ((dif_medicoes_ida < dif_medicoes_volta) || (dif_medicoes_ida == dif_medicoes_volta)){
        esforco = dif_medicoes_ida;
    }
    else if (dif_medicoes_ida > dif_medicoes_volta){
        esforco = dif_medicoes_volta;
    }
    return esforco;
}


int dividindo_str(const string& m){
    istringstream iss(m);
    int qtd;
    iss >> qtd;  // coloca o primeiro elemento da string aq
    cout << qtd << endl;
    int medicoes [qtd];
    int i = 0;
    int value;
    while (iss >> value && i < qtd) {
        medicoes[i] = value;
        i++;
    }

  
    return tamanho_do_esforco(medicoes, qtd);
}

int main(){
    int n;  // qtd de trilhas
    string m;
    int esforco[n];
    cin >> n;

    for (int i = 0 ; i < n ; i++){
        cin >> m; // qtd de pontos de medições
        esforco[i] = dividindo_str(m);
        cout << esforco [i] << endl;
    }

    for (int i = 0 ; i < n; i++){
        cout << esforco[i] << " ";
    }
}

/*
5
4 498 500 498 498
10 60 60 70 70 70 70 80 90 90 100
5 200 190 180 170 160
2 1000 900
4 20 20 20 20
*/
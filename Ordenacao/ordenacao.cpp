#include "ordenacao.hpp"

/* Big(O) ==> O(n) */
bool ordenado(int a[],  unsigned int t){
    int i, ordenado = true;
    for (i = 1; i < t; ++i)
        if (a[i - 1] > a[i]) {
            ordenado = false;
            break;
        }
    return ordenado;
}

/* Big(o) ==> O()*/
void selecao(int a[], unsigned int t){ // verificar se já não está ordenado
    int i, j, min, aux;
    if(ordenado(a,t) == false){
        for (int i = 0 ; i < (t-1) ; i++){
            min = i;
            for (j = (i+1); j < t ; j++){
                if(a[j] < a[min])
                    min=j;
            }
            if (a[i] != a[min]){
                aux = a [i];
                a[min] = aux;
            }
        }
    } 
}

/* TODO: Implementar função */
void insercao(int a[], unsigned int t){
    int i, x;
    if(ordenado(a,t) == false){ // verificar se já não está ordenado
        for (i = 0 ; i < t ; i++){
            x = a[i];

        }
    }
}

/* TODO: Implementar função */
void merge_sort(int a[], unsigned int t, int primeiro, int ultimo){
    int meio;
    if(primeiro < ultimo){
        meio = (primeiro + ultimo) / 2;
        merge_sort(a,t, primeiro, meio);
        merge_sort(a, t, meio+1 , ultimo);
        merge(a, primeiro, meio, meio+1, ultimo);
    }
}
void merge(int a[], int primeiro, int metade, int meio,int ultimo) {
    
}
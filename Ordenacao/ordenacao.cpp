#include "ordenacao.hpp"

/* Big(O) ==> O(n) */
bool ordenado(int a[],  unsigned int t){ // verificar se já não está ordenado
    bool ordenado = true;
    for (unsigned int i = 1; i < t; ++i)
        if (a[i - 1] > a[i]) {
            ordenado = false;
            break;
        }
    return ordenado;
}

/* Big(o) ==> O(n²)*/
void selecao(int a[], unsigned int t){ 
    unsigned int i, j, min, aux;
    if(ordenado(a,t) == false){ // verificar se já não está ordenado   
        for (i = 0; i < (t-1); i++){
            min = i;
            for (j = (i+1); j < t; j++) {
                if(a[j] < a[min])
                    min = j;
            }
            if (a[i] != a[min]) {
                aux = a[i];
                a[i] = a[min];
                a[min] = aux;
            }
        }
    }
}
    /* Big(o) ==>  O(n²)*/
void insercao(int a[], unsigned int t){
        int j, aux;
        if(ordenado(a,t) == false){ // verificar se já não está ordenado    
            for (unsigned int i = 1 ; i < t ; i++){
                aux = a[i];
                for(j = i-1; j >= 0 && a[j] > aux ; j--){
                        a[j+1] = a[j];
                }
                a[j + 1] = aux;
            }
        } 
}

/* Big(o) ==> O(logn)*/
void merge_sort(int a[], unsigned int t){
    int primeiro = 0;
    int ultimo = t-1;
    merge_sort_bt(a, t, primeiro, ultimo);
}
// merge_sort_bt --> função recursiva que será chamada apartir de merge_sort
void merge_sort_bt(int a[], unsigned int t, int primeiro, int ultimo){
    int meio;
    if(!ordenado(a,t)){
        if(primeiro < ultimo){
        meio = (primeiro + ultimo) / 2;
        merge_sort_bt(a,t, primeiro, meio);
        merge_sort_bt(a, t, meio+1 , ultimo);
        // merge(a, primeiro, meio, meio+1, ultimo){
        int meioum = meio+1;
        int* temp = new int[((meio - primeiro) + (ultimo - meioum) + 2)];
        int i, j, k;
        i = primeiro;
        j = meioum;
        k = 0;
        while (i <= meio && j <= ultimo) {
            if (a[i] < a[j])
            temp[k++] = a[i++];
            else
            temp[k++] = a[j++];
        }
        while (i <= meio)
            temp[k++] = a[i++];
        while (j <= ultimo)
            temp[k++] = a[j++];
        for (i = primeiro, j = 0;i <= ultimo;i++, j++)
            a[i] = temp[j];
        delete[] temp;
        }
    }
} 


#ifndef __ORDENACAO__
#define __ORDENACAO__

/*
  Função que retorna se um vetor 'a' de 't' elementos 
  está ordenado não decrescentemente

  Retorno: false Se 'a' não estiver ordenado
           true caso contrário
*/
bool ordenado(int a[], unsigned int t);

/*
  Função que ordena o vetor 'a' de forma não decrescente
  usando o método de ordenação por seleção.
  A ordenação é feita diretamente no vetor 'a'
*/
void selecao(int a[], unsigned int t);

/*
  Função que ordena o vetor 'a' de forma não decrescente
  usando o método de ordenação por inserção.
  A ordenação é feita diretamente no vetor 'a'
*/
void insercao(int a[], unsigned int t);

/*
  Função que ordena o vetor 'a' de forma não decrescente
  usando o método de ordenação merge-sort.
  A ordenação é feita diretamente no vetor 'a'
*/
void merge_sort(int a[], unsigned int t);
void merge_sort_bt(int a[], unsigned int t, int primeiro, int ultimo);
#endif

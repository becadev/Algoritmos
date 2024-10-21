int contar_divisores(int n){
  int d=1,qtd=1;
  while (d!=n){
    if ((n%d)==0)
      qtd++;
    d++;  //Corpo deve modificar resultado da expressão
    }
  return qtd;
}

int contar_divisores(int n){
int qtd=1,d=1;
  do {
    if ((n%d++)==0)
    qtd++;
  } while (d!=n);
  return qtd;
}

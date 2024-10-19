# include <iostream>
# include <vector>
using namespace std;

int main(){
    int n,qtd;
    vector <int> tamanho(n);
    for (int i = 0; i < n; i += 1){
        cin >> tamanho[i];
    }
    cin >> qtd;
    int pedido;
    for (int i = 0; i < qtd; i +=1){
        std::cin >> pedido;
        if (tamanho[pedido]>0){
            tamanho[pedido]-=1;
        }else{
            qtd -=1; 
        }
    }
    std::cout<<qtd<<std::endl;

    return 0;
}
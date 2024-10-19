# include <iostream>
# include <vector>
using namespace std;

int main(){
    int n,qtd,pedido,vendas;
    //Qtd totais de modelos
    std::cin >> n;

    /*  Tamanhos disponiveis por modelo
     1 2 3 4 5 */
    vector <int> tamanho(n);
    for (int i = 0; i < n; i++){
        cin >> tamanho[i];
    }

    // Quantidade de pedidos
    cin >> qtd;
    vendas = qtd;

    for (int i = 0; i < qtd; i++){
        std::cin >> pedido;         //Modelo do pedido

        if (tamanho[pedido-1] > 0){     //Verificando a disponibilidade
            tamanho[pedido-1] -= 1;     // Subtraindo o total do produto
        }else{
            vendas -=1;                 // Se não for vendido subtrai
        }
    }
    std::cout<<vendas<<std::endl;
    return 0;
}
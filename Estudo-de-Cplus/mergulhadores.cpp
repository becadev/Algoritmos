# include <iostream>
# include <vector>
using namespace std;
//  Depois refazer de uma forma mais eficiente
int main(){
        int qtd, vivos,cont=0;
        std::cin >> qtd >> vivos;

        vector<int>total(qtd); // referente ao total de mergulhadores que foram
        vector<int>voltaram(vivos); // referente ao total de mergulhaores que voltaram

        //  Recebe o id dos mergulhadores que voltaram
        for (int i = 0 ; i < vivos ; i++){
            std::cin >> voltaram[i];
        }
        // Faz um array de 1 até qtd
        for (int i=0; i < qtd ; i++){
            total[i] = i+1;
        }
        // Verifica quem não voltou
        for (int j = 0 ; j < vivos ; j++){
            for (int k = 0 ; k < qtd ; k++){
                if (voltaram[j] == total[k]){
                    total[k] = 0;
                }
            }  
        }
        // Mostra quem não voltou ou se voltou todos
        
        for (int i = 0 ; i < qtd ; i++){
            cont+=total[i];       
        }
        if (cont >=1){
            for (int i = 0 ; i<qtd; i++){
                if (total[i] == 0){
                    continue;
                }else{
                    std::cout << total[i] << " "; 
                }
            } 
        }else{
            std::cout << "*" << std::endl; 
        } 
        return 0;
}
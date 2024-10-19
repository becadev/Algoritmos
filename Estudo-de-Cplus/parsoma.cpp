# include <iostream>
# include <vector>
using namespace std;

int main(){
    int qtd,soma,cont=0;
    std :: cin>>qtd>>soma; 
    vector <int> numeros(qtd); 

    for (int i = 0; i < qtd; i += 1){
        std :: cin >> numeros[i];
    }
    
    for (int j = 0; j < qtd; j++){
        for (int k = j + 1 ; k < qtd; k+=1){ // j + 1 evita que o numero conte com ele mesmo
            if (numeros[j]+numeros[k]==soma){
                cont +=1;
                std::cout<<"SIM"<<std::endl;
                return 0;
            }
        }
    }
    if (cont==0){
        std::cout<<"NAO"<<std::endl;
    }
    return 0;
}

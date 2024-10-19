# include <iostream>
# include <vector>
#include <algorithm>
using namespace std;

int main(){
    int qtd, vivos;
    std::cin >> qtd >> vivos;
    vector<int>total(qtd);
    vector<int>voltaram(qtd);
    for (int i = 0 ; i < qtd ; i++){
        std::cin >> voltaram[i];
    }
    sort(voltaram.begin(), voltaram.end());
    for (int i=0; i < qtd ; i++){
        total[i]=i;
    }

    for (int j = 0 ; j < vivos ; j++){
        for (int k = 0 ; k < qtd ; k++){
            if (voltaram[j]==total[k]){
                total.erase (total.begin()+ k);
        }
    }
    if  ((sizeof total/sizeof total[0])>=1){
        for (int i = 0 ; i<sizeof total/sizeof total[0]; i++){
            std::cout << total[i] << " ";
        }
    }else{
        std::cout << "*" << std::endl;
    }
    }
}

// sizeof p / sizeof p[0]
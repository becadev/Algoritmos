# include <iostream>
using namespace std;

int mmc(int b, int d){
    // variavel = (condicao) ? valor_se_verdadeiro : valor_se_falso;
    int maior = (b > d) ? b : d;
    int i = maior;

    while(true){
        if (i % b == 0 && i % d ==0){
            std::cout << d << b << i << std :: endl;
            return i;
        }
        i++;
    }
}

int main(){
    int b,d;
    std:: cin >> b >> d;
    int m = mmc(b,d);
    std ::cout << m << std :: endl;
}
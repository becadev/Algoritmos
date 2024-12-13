# include <iostream>
using namespace std;

int soma(int num[], int s){
     for (int i = 0 ; i < 8; i++ ){
        for (int j = 1 ; j < 7; j++ ){
            if (num[i] + num[j] == s){
                return true;
            }
        }
    }
    return false;
}
int main(){
    int num[8];
    int s;
    std :: cin >> s;
    for (int i = 0 ; i < 8 ; i ++){
        std::cin >> num[i];
    }
    bool resposta = soma(num,s);
    if (resposta){
        std :: cout << "S" << std::endl;
    }else{
        std :: cout << "N" << std::endl;
    }
    return 0;
}
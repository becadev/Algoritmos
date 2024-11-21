# include <iostream>
using namespace std;

int triangulo(int num[], int n){
    for (int i = 0 ; i < n ; i ++){
        for (int j = 1 ; j < n ; j ++){
            for (int k = 2 ; k < n ; k++){
                if ((num[i]*num[i] == num[j]*num[j] + num[k]*num[k]) ||  (num[j]*num[j] == num[i]*num[i] + num[k]*num[k])  ||  (num[k]*num[k] == num[i]*num[i] + num[j]*num[j])){
                    return true;
                }
            }
        }
    }
    return false;
}

int main(){
    int n;
    std :: cin >> n;
    int num[n];
    for (int i = 0 ; i < n ; i++){
        std :: cin >> num[i];
    }
    bool resposta = triangulo(num, n);
    if (resposta){
        std :: cout << "S" << std:: endl;
    }else{
        std :: cout << "N" << std:: endl;
    }
}
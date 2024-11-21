# include <iostream>
# include <cmath>
using namespace std;


int calc(int x1, int x2, int y1, int y2);

int ponto (int coord[][100], int qtd){
    int resposta[2][4];
    coord[0][0];
    int x1 = coord[0][0];
    int y1 = coord[1][0];
    int x2 = coord[0][1];
    int y2 = coord[1][1];

    int resp_x1 = x1;
    int resp_y1 = y1;
    int resp_x2 = x2;
    int resp_y2 = y2;

    int maior = calc(x1,x2,y1,y2);
    int resultado = 0;

    for (int i =  1; i < qtd ; i++){
        coord[0][i];
        int y1 = coord[1][i];
        for (int k = i ; k < qtd ; k++){
            int x2 = coord[0][k];
            int y2 = coord[1][k];

            int menor = calc(x1,x2,y1,y2);
            if (maior < menor){
                int resp_x1 = x1;
                int resp_y1 = y1;
                int resp_x2 = x2;
                int resp_y2 = y2;
                maior = menor;
            }
            if (resultado < menor){
                resultado = menor;
            }
        }
    }
     std:: cout << resp_x1 << std::endl;
     std:: cout << resp_y1 << std::endl;
     std:: cout << resp_x2 << std::endl;
     std:: cout << resp_y2 << std::endl;
    return 0;
}

int calc (int x1 , int x2, int y1, int y2){
    return sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
}

int main(){
    int qtd;
    std::cin >> qtd;
    int coord[2][100];
    for (int i = 0 ; i < qtd ; i++){
        std::cin >> coord[0][i] >> coord[1][i];
    }
    int resposta = ponto(coord, qtd);

    std:: cout << resposta << std::endl;
    return 0;
}
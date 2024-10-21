/*
Escreva um algoritmo que calcule a quantidade de postes a serem colocados em uma rua. O algoritmo tem como
entrada a distância do início ao fim da rua, um número inteiro m, em metros, e a distância entre 2 (dois) postes p,
também em metros. Há sempre um poste no ponto 0 da rua e outro no ponto m, que é o final da rua. Seu programa
deve mostrar a quantidade de postes a serem colocados e a distância entre os dois últimos postes. Lembre-se que
há sempre um poste no início da rua e outro no final. A distância entre cada par de postes é o valor, em metros,
lido pelo programa, com exceção da distância entre os dois últimos postes da rua.
*/

# include <iostream>
using namespace std;

int main(){
    int distancia,distancia_postes, qtd = 2, soma_metros=0;     // Qtd inicial é igual a dois pois sempre haverá um poste no início e outro non final.
    std::cin >> distancia >> distancia_postes;

    do{
        soma_metros += distancia_postes;
        qtd += 1;
    }while(distancia - soma_metros > distancia_postes);

    std::cout << "Quantidade de postes nessa rua: " << qtd << std::endl;
    return 0;
}

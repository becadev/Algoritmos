# include <iostream>
using namespace std;

int main(){
    double nota_max,nota_aluno;
    std::cin >> nota_max >> nota_aluno;
    
    int media = (nota_aluno*100)/nota_max;
    std::cout << media << std::endl;

    return 0;
}
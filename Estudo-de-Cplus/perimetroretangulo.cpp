/*Escreva um programa que leia dois lados l1 e l2 que forma um retângulo, como mostrado a seguir, e mostre o
perímetro do retângulo.*/

# include <iostream>
# include <iomanip>

int perimetro(double l1, double l2){
    double p = (2.0*l1) + (2.0*l2);
    return p;
}
int main(){
    double l1, l2;
    std::cin >> l1 >> l2;
    double peri = perimetro(l1,l2);
    std::cout << std :: fixed << std::setprecision(1) <<peri << std::endl;
    return 0;
}
#include <iostream>
using namespace std;

struct fracao{
    int numerador;
    int denominador;
};

int mmc(int b, int d){
    // variavel = (condicao) ? valor_se_verdadeiro : valor_se_falso;
    int maior = (b > d) ? b : d;
    int i = maior;

    while(true){
        if (i % b == 0 && i % d ==0){
            return i;
        }
        i++;
    }
}

int mdc(int a, int b){ // MDC pelo método de euclides
    int aux;
    while (b!=0){
        aux = a % b;
        a = b;
        b = aux;
    }
    return a;
}

fracao soma(fracao & f1, fracao & f2){
        fracao f3;

        int denominador_comum = mmc(f1.denominador,f2.denominador); // (b,d)

        f3.numerador =  (f1.numerador * denominador_comum / f1.denominador) + (f2.numerador * denominador_comum / f2.denominador);
        
        f3.denominador = denominador_comum;

        int divisor_comum = mdc(f3.numerador, f3.denominador);

        f3.numerador /= divisor_comum;

        f3.denominador /= divisor_comum;
        return f3;
}

int main(){
    int a,b,c,d;
    std::cin >> a >> b >> c >> d;

    fracao f1 = {a,b};  // declarando quem é quem no struct (numeraor, denominador)
    fracao f2 = {c,d};
    fracao resultado = soma (f1,f2);
    
    std :: cout << resultado.numerador <<  "/" << resultado.denominador << std :: endl;
    return 0;
    
}
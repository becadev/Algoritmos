# include <iostream>
# include <iomanip>
using namespace std;


double raiz(double a){
    double rn = a/2;
    rn = (raiz(rn-1) + (a/(raiz(rn-1))))/2;
    std :: cout << rn << std:: endl;
    return rn;
}
int main(){
    int a;
    std::cin >> a;
    std :: cout << std::fixed << setprecision(3) << raiz(a) << std::endl;
    return 0;
}
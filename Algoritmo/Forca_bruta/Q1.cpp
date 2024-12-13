#include <iostream>
using namespace std;

int main(){
    int alt, larg, a1, l1, a2, l2;
    std::cin >> alt >> larg;

    std::cin >> a1 >> l1;
    std::cin >> a2 >> l2;


    if ((a1+a2 < alt) && (l1 < larg && l2< larg) || ((a2+l1 < alt) && (a1 < larg && l2< larg)) || ((a1+l2 < alt) && (a2 < larg && l1< larg))){
        std::cout << "S" << std::endl;
    }else{
        std::cout << "N" << std::endl;
    }
    return 0;
}

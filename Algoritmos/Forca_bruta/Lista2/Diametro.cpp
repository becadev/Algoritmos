# include <iostream>
# include <iomanip>

int main(){
    float r,a;
    std::cin>>r;
    float pi = 3.14159;
    r = r/2.0;
    a = pi*(r*r);
    std::cout << std::fixed << std:: setprecision(5) << a << std::endl;
    return 0;
}

/*
Diametro    |        float      |   double
1.00000     |       0.78540     |   0.78540
10.00000    |                   |   78.53975
50000.00000 |                   |   1963493750.00000
100000.00000|                   |   7853975000.00000
100000.00000|                   |   7853975000.00000
200000.00000|31415902208.00000  |   31415900000.00000
1.56780     |                   |   1.93050
123.45678   |11970.69629        |   11970.69610

*/
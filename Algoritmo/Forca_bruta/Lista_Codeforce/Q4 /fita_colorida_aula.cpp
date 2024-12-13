// Resolvida pelo professor
// Complexidade: O(n)
#include <iostream>

int main(){
    int n;
    std::cin >> n;
    int a[n+2];
    a[0] = a[n-1] = -1;
    for (int i=1 ; i<=n ; ++i)
        std::cin >> a[i];
    
    for (int i=1 ; i<=9 ; ++i){
        for (int j=1 ; j<=n ; j++)
            if ((a[j-1]==i-1 or a[j+1]==i-1) and (a[j]>i or a[j]==-1))
                a[j] = i;
    }
    for (int i=1 ; i<=n ; ++i)
        if (a[i] == -1)
            a[i] = 9;
    for (int i=1 ; i<=n ; ++i)
        std::cout << a[i] << " ";
    std::cout << std::endl;
    return 0;
}
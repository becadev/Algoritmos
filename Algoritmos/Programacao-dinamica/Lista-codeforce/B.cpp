// Big(O) : 
// Machu picchu
# include <bits/stdc++.h>
using namespace std;

const int INF = 10000;
std::vector<std::vector<int>> dp;


int machu_picchu_pd(int a[20][20],int index, int l, int c){
    if(c == 0) return 0;
    return 0;
}

int main(){
    int n,m;
    cin >> n >> m;
    int a[n][m];
    dp.resize(n+10,std::vector<int>(m+10,-1));

    for(int l = 0; l < n ; l++){
        for (int c = 0 ; c < n ; c++){
            cin >> a[l][c];
        }
    }
    int n = INF;
    for(int i = 0; i < n ; i++){
        n = min(n, machu_picchu_pd(a,i, n,m));
    }


    return 0;
}
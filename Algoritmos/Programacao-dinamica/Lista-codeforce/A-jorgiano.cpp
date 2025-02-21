#include <iostream>
#include <vector>
#include <algorithm>

const int INF = 1000000000;

/*
5 7
20 10 5 2 1

  0   1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21
0 20  I I I I I I I - -  -  -  -  -  -  -  -  -  -  -  -  -
1 10  I I I I I I I - -  -  -  -  -  -  -  -  -  -  -  -  -
2 5   I I I I 1 2 2 - -  -  -  -  -  -  -  -  -  -  -  -  -
3 2   I 1 2 2 3 3 2 - -  -  -  -  -  -  -  -  -  -  -  -  -
4 1   1 2 2 3 3 2 3 - -  -  -  -  -  -  -  -  -  -  -  -  -
*/
std::vector<std::vector<int>> dp;
int troco_bt(std::vector<int> &c, int v){
    if (v == 0)
        return 0;
    if (v<0)
        return INF;
    int ans = INF;
    // 1 + min (troco_bt(v-1), troco_bt(v-2), troco_bt(v-5), troco_bt(v-10), troco_bt(v-20));
    if (dp[0][v] != -1){ // Já calculei para o valor v?
        for (unsigned int i=0 ; i<c.size() ; ++i){
            ans = std::min(ans, dp[i][v]);
        }
    } else { // Se nao calculou, calcule
        for (unsigned int i=0 ; i<c.size() ; ++i){
            if (dp[i][v] != -1)
                return dp[i][v];
            else
                dp[i][v] = 1 + troco_bt(c, v-c[i]);
            ans = std::min(ans, dp[i][v]);
        }
    }
    return ans;
}

int main(){
    int n, v;
    std::cin >> n >> v;
    dp.resize(n, std::vector<int>(v+10, -1));
    std::vector<int> c(n);
    for (auto &x: c) std::cin >> x;
    std::cout << troco_bt(c, v) << std::endl;
    return 0;
}
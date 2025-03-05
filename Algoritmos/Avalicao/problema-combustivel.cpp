/*
Entrada:
n = 3 (número de postos)
P = {90, 180, 270} km
t = {10, 5, 7} minutos
Distância total entre C1 e C2 = 300 km (d)

Entrada:
m = 4
p = 70 140 190 240
t = 3 12 4 7
Distância total entre C1 e C2 = 280 km (d)

Saída Esperada:
Paradas: 70 -> 140 -> 240 -> C2
Tempo total: 3+12+7 -> 22 minutos
*/
// Eu tenho que testar todas possilidades de paradas, e pegar a com menor tempo que seja válida - válida = paradas que eu consigo chegar com 100km de autonomia

# include <bits/stdc++.h>
using namespace std;
int INF = 100000;

int tempo_viagem(std::vector<int & p, std::vector<int &t, int d, int tempo, int n){
    if(d <= 0) return 0;
    if(d > 0) return INF;
    if(p[d] + )


    int ans = INF;
    for(int i = 0 ; i < p.size() ; i++){
        if(100 - p[i] >= 0) // 
            tempo+= t[i];
    }

}


int main(){
    int n, d;
    cin >> n >> d;
    std::vector<int> p(n);
    std::vector<int> t(n);
    for(int i = 0 ; i < n ; i++)
        cin >> p[i];
    for(int i = 0 ; i < n ; i++)
        cin >> t[i];

    cout << tempo_viagem(p,t,d,0,n-1) << endl;
    return 0;
}
# include <iostream>
# include <algorithm>
using namespace std;

int main(){
    int n, cont = 0, cont2 = 0;
    cin >> n;
    int fita[n];
    int fitas_coloridas[n];
    int fitas_coloridas2[n];
    int i = 0;
    int n2 = n;
    for (i = 0 ; i < n ; i++){
        cin >> fita[i];
    }
    for (i = 0 ; i < n ; i++){
        if (fita[i] != 0){
            n2--;
            for (int k = i+1 ; k < n+1 ; k++){
                    cont+= 1;
                    if (fita[k] == 0){
                        break;
                    }
                }
            // For por incremento
            for (int j = n2 ; j >= 0 ; j--){
                    cont2+= 1;
                    if (fita[j] == 0){                    
                        break;
                    }
                }
            }
        // }
        fitas_coloridas2[i] = cont;
        fitas_coloridas[i]  = cont2;
        cont = 0;
        cont2 = 0;
    }

    for (i = 0 ; i < n ; i ++ ){
        if (fitas_coloridas[i] > fitas_coloridas2[i]) fitas_coloridas[i] = fitas_coloridas2[i];
    }

    
    for (int i = 0 ; i < n ; i++){
        cout << fitas_coloridas[i] <<  " ";
    }
    cout << endl;
    return 0;
}

//*  1 0 1 7 6 5 4 3 2 1 0 1 1 
//   1 0 1 3 3 3 3 3 2 1 0 1 1
//  1 0 1 2 3 4 4 3 2 1 0 1 2
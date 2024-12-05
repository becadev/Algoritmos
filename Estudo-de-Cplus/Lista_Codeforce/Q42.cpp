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
            cont ++;
            // fitas_coloridas2[i] = cont;
            fitas_coloridas[i]  = cont;
        }
        if (fita[i]==0){
            cont = 0;
            fitas_coloridas[i]  = cont;
        }
    }
     for (i = n ; i >= 0 ; i--){
        if (fita[i] != 0){
            cont2 ++;
            // fitas_coloridas2[i] = cont;
            fitas_coloridas2[i]  = cont2;
        }
        if (fita[i]==0){
            cont2 = 0;
            fitas_coloridas2[i]  = cont2;
        }
    }

    for (int i = 0 ; i < n ; i++){
        if (fitas_coloridas[i]==0){
            fitas_coloridas[i-1] = 1;
            fitas_coloridas[i+1] = 1;
        }
    }
    for (int i = 0 ; i < n ; i++){
        cout << fitas_coloridas[i] <<  " ";
    }
    cout << endl;
    for (int i = 0 ; i < n ; i++){
        cout << fitas_coloridas2[i] <<  " ";
   }
    cout << endl;
    return 0;
}

//*  1 0 1 7 6 5 4 3 2 1 0 1 1 
//   1 0 1 3 3 3 3 3 2 1 0 1 1
//  1 0 1 2 3 4 4 3 2 1 0 1 2
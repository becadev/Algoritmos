#include <iostream>
using namespace std;

int main(){
  int *data, size = 0, capacity = 10, x;
  data = new int[capacity];
  while(cin>>x, x!=-1){
    if(size == capacity){
        int *new_array = new int [capacity+10];
   
        for(int i=0 ; i<size ; i++){
            new_array[i] = data[i];
        }
        int *old_array = data;
        data = new_array;
        delete[] old_array;
        capacity = capacity+10;
    }
    data[size++] = x;
  }
  delete[] data;
  return 0;
}
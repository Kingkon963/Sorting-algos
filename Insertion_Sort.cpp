#include <iostream>
using namespace std;


int main(){
  int arr[] = {9,8,7,6,5,4,3,2,1}, LOC=-1;
  int n = sizeof(arr)/sizeof(int);
  
  for(int k = 1; k < n; k++){
    int temp = arr[k];
    int ptr = k -1;
    while(temp < arr[ptr]){
      arr[ptr + 1] = arr[ptr];
      ptr--;
      if(ptr < 0) break;
    }
    arr[ptr + 1] = temp;
  }

  for(int i:arr){
    cout << i << " ";
  }
  
}
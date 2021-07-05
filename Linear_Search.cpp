#include <iostream>
using namespace std;

bool linear_search(int arr[], int size, int key){
  for(int i = 0; i < size; i++){
    if(arr[i] == key)
      return true;
  }
  return false;
}

int main(){
  int arr[] = {13,51,27,85,66,23,0,57};
  int n = sizeof(arr) / sizeof(int);

   cout << linear_search(arr, n, 0);  
}
#include <iostream>
using namespace std;

void Min(int arr[], int k, int n, int &LOC){
  int minimum = arr[k];
  LOC = k;
  for(int i=k+1; i<n; i++){
    if(minimum > arr[i]){
      minimum = arr[i];
      LOC = i;
    }
  }
}

void Interchange(int &a, int &b){
  int temp = a;
  a = b;
  b = temp;
}

void SelectionSort(int arr[], int k, int n){
  int LOC=-1;
  for(int i=k; i<(n-1); i++){
    Min(arr, i, n, LOC);
    Interchange(arr[i], arr[LOC]);
  }
}

int main(){
  int arr[] = {2, 3, 1, 5}, LOC=-1;
  
  SelectionSort(arr, 0, 4);

  for(int i:arr){
    cout << i << " ";
  }
  
}
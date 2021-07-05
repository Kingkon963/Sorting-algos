#include <iostream>
#include <stdlib.h>
#include <time.h>
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

int* arrayGenerator(int n, int start = 0, int end = 10){
  int *out = new int [n];
  srand(time(0));
  for(int i = 0; i < n; i++){
    out[i] = (rand() % end) + start;
  }
  return out;
}

int main(){
  int *arr, size = 100;
  arr = arrayGenerator(size, 10, 100);

  SelectionSort(arr, 0, size);

  for(int i = 0; i < size; i++){
    cout << arr[i] << " ";
  }
}
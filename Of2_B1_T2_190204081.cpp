#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <list>
using namespace std;

void swap(int &a, int &b){
  int temp = a;
  a = b;
  b = temp;
}

void QuickSort(int arr[], int f, int l){
  if(f < l){
    int i = f + 1;
    int j = l;
    while(arr[i] < arr[f]) i++;
    while(arr[j] > arr[f]) j--;
    while(i < j){
      swap(arr[i], arr[j]);
      while(arr[i] < arr[f]) i++;
      while(arr[j] > arr[f]) j--;
    }
    swap(arr[j], arr[f]);
    QuickSort(arr, f, j-1);
    QuickSort(arr, j+1, l);
  }
}

int main(){
  srand(time(NULL));
  int arr[10];
  int n = sizeof(arr)/sizeof(int);

  for(int i=0; i<n; i++){
    arr[i] = rand() % 20;
  }
  
  QuickSort(arr, 0, n-1);
  for(int i=0; i<n; i++){
    cout << arr[i] << " ";
  }
}
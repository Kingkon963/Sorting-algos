#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

void interchange(int &a, int &b){
  int temp = a;
  a = b;
  b = temp;
}

void bubble_sort(int arr[], int n){
  int swapped;
  for(int k =  1; k <= n; k++){
    swapped = 0;
    for(int st = 0; st < n-k; st++){
      if(arr[st] > arr[st+1]){
        interchange(arr[st], arr[st+1]);
        swapped = 1;
      }
    }
    if(!swapped) break;
  }
}

int main(){
  time_t t;
  srand((unsigned) time(&t));

  int arr[10];
  int n = sizeof(arr) / sizeof(int);

  for(int i=0; i<n; i++){
    arr[i] = rand();
  }


  bubble_sort(arr, n);  

  for(int i:arr){
    cout << i << " ";
  }
}
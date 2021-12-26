#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <list>
using namespace std;

void MERGE(int arr[], int p, int q, int r){
  int n1 = q - p + 1;
  int n2 = r - q;

  list<int> L, R;
  
  for(int i = p; i <= q; i++){
    L.push_back(arr[i]);
  }
  for(int j = q+1; j <= r; j++){
    R.push_back(arr[j]);
  }
  
  L.push_back(INT_MAX);
  R.push_back(INT_MAX);

  for(int k = p; (k <= r); k++){
    if(L.front() < R.front()){
      arr[k] = L.front();
      L.pop_front();
    }
    else{
      arr[k] = R.front();
      R.pop_front();
    }
  }
}

void MERGE_SORT(int arr[], int p, int r){
  if(p < r){
    int q = (p + r)/2;
    MERGE_SORT(arr, p, q);
    MERGE_SORT(arr, q + 1, r);
    MERGE(arr, p, q, r);
  }
}

int main(){
  srand(time(NULL));
  int arr[20];
  int n = sizeof(arr)/sizeof(int);

  for(int i=0; i<20; i++){
    arr[i] = rand() % 50;
  }
  
  MERGE_SORT(arr, 0, n-1);
  
  for(int i=0; i<n; i++){
    cout << arr[i] << " ";
  }
}
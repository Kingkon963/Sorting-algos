#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void Max(int arr[], int k, int n, int &LOC){
  int minimum = arr[k];
  LOC = k;
  for(int i=k+1; i<n; i++){
    if(minimum < arr[i]){
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
    Max(arr, i, n, LOC);
    Interchange(arr[i], arr[LOC]);
  }
}

bool BinarySearch(int arr[], int k, int n, int item, int &LOC){
  int BEG = k, END = n-1;
  int MID = (int) (BEG + END) / 2;
  while((BEG <= END) && (arr[MID] != item)){
    if(item < arr[MID]) 
      BEG = MID + 1;
    else
      END = MID - 1;
    
    MID = (int) (BEG + END) / 2;
  }

  if(arr[MID] == item){
    LOC = MID;
    return true;
  }
  else{
    LOC = -1;
    return false;
  }
}

int main(){
  clock_t start_time, end_time;
  start_time = clock();
  int arr[] = {50,30,20,11,17,56,89,89,54,26,35,78,14,23,24,25,26,47,85,1,4,56,87,8,2,1,45,65,47};
  int n = sizeof(arr)/sizeof(int);
  int pos;

  SelectionSort(arr, 0, n);

  for(int i:arr){
    cout << i << " ";
  }

  cout << endl;

  if(BinarySearch(arr, 0, n, 89, pos)){
    cout << arr[pos] << " Found at Index "<< pos << endl;
  }
  else{
    cout << "Couldn't Found" << endl;
  }
  end_time = clock();

  double total_time = (double) (end_time-start_time)/CLOCKS_PER_SEC;
  cout << "Required Time: " << total_time;
}
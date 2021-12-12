#include <iostream>
using namespace std;


void swap(int &a, int &b){
  int temp = a;
  a = b;
  b = temp;
}

int partition(int A[], int start, int end){
  int pivot = A[end];
  int partIndx = start;
  for(int i=start; i<end; i++){
    if(A[i] <= pivot){
      swap(A[partIndx], A[i]);
      partIndx++;
    }
  }
  swap(A[partIndx], A[end]);
  return partIndx;
}

void quickSort(int A[], int start, int end){
  if(start >= end) return;
  int partIndx = partition(A, start, end);
  quickSort(A, start, partIndx - 1);
  quickSort(A, partIndx + 1, end);
}

int main() {
  int arr[] = {3, 5, -1, 0, 7, 3, 45, 99, -9, 98};
  int arrSize = sizeof(arr)/sizeof(int);
  quickSort(arr, 0, arrSize-1);

  for(int i:arr){
    cout << i << " ";
  }
}
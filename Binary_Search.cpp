#include <iostream>
using namespace std;

bool BinarySearch(int arr[], int k, int n, int item, int &LOC){
  int BEG = k, END = n-1;
  int MID = (int) (BEG + END) / 2;
  while((BEG <= END) && (arr[MID] != item)){
    if(item < arr[MID]) 
      END = MID - 1;
    else
      BEG = MID + 1;
    
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
  int data[] = {-7,1,2,3,4,5,6,7,8,9};
  int n = sizeof(data)/sizeof(int);
  int POS;

  if(BinarySearch(data, 0, 8, -7, POS)){
    cout << data[POS] << endl;
  }
  else{
    cout << "Couldn't Find" << endl;
  }
}
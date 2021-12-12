#include <bits/stdc++.h>
using namespace std;

class StackList {
  private:
    int *arr;
    int top;

  public:
    StackList(){
      arr = new int(1000);
      top = -1;
    }

    bool isEmpty(){
      if(top == -1) return true;
      return false;
    }

    int size(){
      return top + 1;
    }

    void push(int val){
      arr[++top] = val;
    }

    int pop(){
      if(!isEmpty())
        return arr[top--];
      else
        throw string("Stack is empty!");
        
    }

    void print(){
      for(int i=0; i<=top; i++){
        cout << arr[i] << " ";
      }
      cout << endl;
    }
};

int main()
{
    StackList st;
    st.print();
    st.push(3);
    st.push(5);
    st.print();
    cout << "Size: " << st.size() << endl;
    st.pop();

    return 0;
}
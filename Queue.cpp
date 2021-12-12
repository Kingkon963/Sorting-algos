#include <bits/stdc++.h>
#include "LinkedList.h"
using namespace std;

class QueueList {
  private:
    LinkedList list;
    
  public:
    QueueList(){
      list = LinkedList();
    }

    bool isEmpty(){
      if(list.size() == 0) return true;
      return false;
    }

    int size(){
      return list.size();
    }

    void enqueue(int val){
      list.push_back(val);
    }

    int dequeue(){
      return list.pop_front();
    }

    void print(){
      list.print();
    }
};

int main()
{
    QueueList ql;
    ql.enqueue(9);
    ql.enqueue(17);
    ql.enqueue(57);
    ql.print();
    cout << "Size: " << ql.size() << endl;  
    cout << "dequeue: " << ql.dequeue() << endl;
    ql.print();
    cout << "Size: " << ql.size() << endl;  
    return 0;
}
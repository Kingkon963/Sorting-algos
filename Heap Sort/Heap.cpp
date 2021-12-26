#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

class Heap
{
private:
  int left(int parent)
  {
    return (parent * 2) + 1;
  }

  int right(int parent)
  {
    return left(parent) + 1;
  }

  int parent(int child)
  {
    return child / 2;
  }

  vector<int> heap;

public:
  Heap()
  {
  }
  Heap(int heap[], int heap_size)
  {
    for (int i = 0; i < heap_size; i++)
      this->heap.push_back(heap[i]);

    for (int i = heap_size / 2; i >= 1; i--)
      min_heapify(i - 1);
  }

  void print()
  {
    for (int i : heap)
    {
      cout << i << " ";
    }
    cout << endl;
  }

  void min_heapify(int node)
  {
    int smallest = node;
    int l = left(node);
    int r = right(node);

    if (l < heap.size() && this->heap[l] < this->heap[smallest])
      smallest = l;

    if (r < heap.size() && this->heap[r] < this->heap[smallest])
      smallest = r;

    if (smallest != node)
    {
      swap(this->heap[smallest], this->heap[node]);
      min_heapify(smallest);
    }
  }

  int delRoot()
  {
    int deletedRoot = heap[0];
    heap.erase(heap.begin());
    for (int i = heap.size() / 2; i >= 1; i--)
      min_heapify(i - 1);
    return deletedRoot;
  }

  void add(int n)
  {
    heap.push_back(n);
    for (int i = heap.size() / 2; i >= 1; i--)
      min_heapify(i - 1);
  }

  vector<int> minHeap_sort()
  {
    vector<int> out;
    while (!heap.empty())
    {
      out.push_back(delRoot());
    }
    return out;
  }
};

class PriorityQueue
{
  private:
   Heap H;
   int size; 
  public:
  PriorityQueue(int arr[], int size){
    this->size = size;
    for(int i=0; i<size; i++) H.add(arr[i]);
  }

  void enqueue(int n){
    H.add(n);
    size++;
  }
  int dequeue() {
    if(size > 0){
      size--;
      return H.delRoot();
    }
    cout << "Queue is Empty" << endl;
    return -1;
  }
  void print() {
    H.print();
  }
};

int main()
{
  int heap_arr[7] = {97, 88, 95, 66, 55, 95, 48};

  Heap heap(heap_arr, 7);

  heap.print();

  cout << "----Heap Sorting----" << endl;

  for (int i : heap.minHeap_sort())
  {
    cout << i << " ";
  }
  cout << endl;

  PriorityQueue pq(heap_arr, 7);
  pq.print();
  cout << pq.dequeue() << endl;
  cout << pq.dequeue() << endl;
  cout << pq.dequeue() << endl;
  cout << pq.dequeue() << endl;
  cout << pq.dequeue() << endl;
  cout << pq.dequeue() << endl;
  cout << pq.dequeue() << endl;
  cout << pq.dequeue() << endl;

  return 0;
}
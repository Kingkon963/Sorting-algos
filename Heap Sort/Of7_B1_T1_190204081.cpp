#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
#define CLS system("cls");
#define endl "\n"

int left(int parent){
    return (parent * 2) + 1;
}

int right(int parent){
    return left(parent) + 1;
}

int parent(int child){
    return child / 2;
}

void min_heapify(int heap[], int heap_size, int node){
    int smallest = node;
    int l = left(node);
    int r = right(node);

    if(l <= heap_size && heap[l] < heap[smallest])
        smallest = l;

    if(r <= heap_size && heap[r] < heap[smallest])
        smallest = r;

    if(smallest != node){
        swap(heap[smallest], heap[node]);
        min_heapify(heap, heap_size, smallest);
    }
}

void build_min_heap(int heap[], int heap_size){
    for(int i = heap_size / 2; i >= 1; i--)
        min_heapify(heap, heap_size, i-1);
}

vector<int> minHeap_sort(int heap[], int heap_size){
    vector<int> out;
    for(int i = heap_size - 1; i >= 1; i--){
        out.push_back(heap[0]);
        swap(heap[0], heap[i]);
        min_heapify(heap, i-1, 0);
    }
    out.push_back(heap[0]);
    return out;
}

int main()
{
    FAST
    int heap[7] = {97, 88, 95, 66, 55, 95, 48};
    build_min_heap(heap, 7);

    for(int i:heap){
        cout << i << ' ';
    }
    cout << endl << "----Sorting----" << endl;

    for(int i:minHeap_sort(heap, 7)){
        cout << i << " ";
    }
   
    return 0;
}
#include<bits/stdc++.h>
#include "../LinkedList.h"
using namespace std;

// struct Node
// {
//     int data;
//     Node* next;
// };

class Queue{
  private:
    Node* head;
    int SIZE;
  public:
    Queue(){
      head = NULL;
      SIZE = 0;
    }
    
    void enqueue(int n){
      SIZE++;
      Node* temp = new Node();
      temp->data = n;
      temp->next = NULL;

      Node* ptr = head;
      if(ptr == NULL){
        head = temp;
        return;
      }
      while(ptr!=NULL){
        if(ptr->next == NULL){
          ptr->next = temp;
          break;
        }
        ptr = ptr->next;
      }
    }

    int dequeue(){
      int out = -1;
      if(head != NULL){
        SIZE--;
        Node *temp = head;
        head = head->next;
        out = temp->data;
        delete temp;
      }
      return out;
    }

    bool isEmpty(){
      return head == NULL;
    }

    int size(){
      return SIZE;
    }

    void print(){
      Node* temp = head;
      while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
      }
      cout << endl;
    }

};

class Graph {
 
    // Number of vertex
    int v;
 
    // Number of edges
    int e;
 
    // Adjacency matrix
    int** adj;

    // Linked List
    LinkedList *adjLL;
 
public:
    Graph(int v, int e);
 
    void addEdge(int start, int e);
 
    void showMatrx();

    void showAdjLL();

    void BFS(int start);
};

Graph::Graph(int v, int e)
{
    this->v = v + 1;
    this->e = e + 1;
    adj = new int*[this->v];
    for (int row = 1; row < this->v; row++) {
        adj[row] = new int[this->v];
        for (int column = 1; column < this->v; column++) {
            adj[row][column] = 0;
        }
    }

    this->adjLL = new LinkedList[this->v];
}


void Graph::addEdge(int start, int e)
{
    // Considering a unidirectional edge
    adj[start][e] = 1;
    // adj[e][start] = 1;
    adjLL[start].push_back(e);
}

void Graph::showMatrx(){
  for(int r = 1; r < this->v; r++){
    for(int c = 1; c < this->v; c++){
      cout << adj[r][c] << " ";
    }
    cout << endl;
  }
}

void Graph::showAdjLL(){
  for(int i=1; i < v; i++){
    cout << i << " -> ";
    adjLL[i].print();
  }
}

void Graph::BFS(int start){
    Queue q;
    // Step 1
        vector<bool> ready(v, true);
        vector<bool> waiting(v, false);
        vector<bool> processed(v, false);
    // Step 2
        q.enqueue(start);
        waiting[start] = true;
    // Step 3
        while(!q.isEmpty()){
            // Step 4
            int nodeN = q.dequeue();
            processed[nodeN] = true;
            // Step 5
            for(int i = 1 ; i < v; i++){
                if(adjLL[nodeN].has(i) && !(processed[i]) && ready[i] && !(waiting[i])){
                    q.enqueue(i);
                    waiting[i] = true;
                    cout << nodeN << "->" << i << endl;
                }
            }
        }
    
}



int main(){
    int v,e;
    cout<<"Enter no of node"<<endl;
    cin>>v;

    cout<<"Enter no of Edge:"<<endl;
    cin>>e;
 
    // Create the graph
    Graph G(v, e);

    int so,des;
    for(int i=0; i<e; i++)
    {
        printf("Enter source and destination: ");
        scanf("%d%d",&so,&des);
        G.addEdge(so, des);
    }

    
    G.showMatrx();
    G.showAdjLL();

    int startingNode;
    
    cout<<"Starting node"<<endl;
    cin>>startingNode;
    cout<<"BFS traversal"<<endl;
    G.BFS(startingNode);

    return 0;
}
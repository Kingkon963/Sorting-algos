#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

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
 
public:
    Graph(int v, int e);
 
    void addEdge(int start, int e);
 
    void BFS(int start);
};

Graph::Graph(int v, int e)
{
    this->v = v;
    this->e = e;
    adj = new int*[v];
    for (int row = 0; row < v; row++) {
        adj[row] = new int[v];
        for (int column = 0; column < v; column++) {
            adj[row][column] = 0;
        }
    }
}


void Graph::addEdge(int start, int e)
{
    // Considering a unidirectional edge
    adj[start][e] = 1;
    // adj[e][start] = 1;
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
            for(int i = 0 ; i < v; i++){
                if(adj[nodeN][i] == 1 && !(processed[i]) && ready[i] && !(waiting[i])){
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
    Graph G(200, 200);

    int so,des;
    for(int i=0; i<e; i++)
    {
        printf("Enter source and destination: ");
        scanf("%d%d",&so,&des);
        G.addEdge(so, des);
    }

    int startingNode;
    
    cout<<"Starting node"<<endl;
    cin>>startingNode;
    
    cout<<"BFS traversal"<<endl;
    G.BFS(startingNode);

    return 0;

}
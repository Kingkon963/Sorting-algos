#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

class Stack{
  private:
    Node* head;
  public:
    Stack(){
      head= NULL;
    }
    
    void push(int n){
      Node* temp = new Node();
      temp->data = n;
      temp->next = head;
      head = temp;
    }

    int pop(){
      int out = -1;
      if(!isEmpty()){
        Node *t = head;
        head = head->next;
        out = t->data;
        delete t;
      }
      return out;
    }

    bool isEmpty(){
      return head == NULL;
    }

    int size(){
      int count = 0;
      Node* temp = head;
      while(temp != NULL){
        count++;
        temp = temp->next;
      }
      return count;
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
 
    void DFS(int start);
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
    // Considering a bidirectional edge
    adj[start][e] = 1;
    adj[e][start] = 1;
}

void Graph::DFS(int start){
    Stack s;
    // Step 1
        vector<bool> ready(v, true);
        vector<bool> waiting(v, false);
        vector<bool> processed(v, false);
    // Step 2
        s.push(start);
        waiting[start] = true;
    // Step 3
        while(!s.isEmpty()){
            // Step 4
            int nodeN = s.pop();
            processed[nodeN] = true;
            // Step 5
            for(int i = 0 ; i < v; i++){
                if(adj[nodeN][i] == 1 && !(processed[i]) && ready[i] && !(waiting[i])){
                    s.push(i);
                    processed[i] = true;
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
    
    cout<<"DFS traversal"<<endl;
    G.DFS(startingNode);

    return 0;

}
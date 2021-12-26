#include<bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  Node *next;
};

class LinkedList{
  private:
    Node* head;
    int listSize;
  public:
    LinkedList(){
      head = NULL;
      listSize = 0;
    }
    bool isEmpty(){
      if(head == NULL) return true;
      return false;
    }

    int size(){
      return listSize;
    }

    void push_front(int val){
      Node *temp = new Node();
      temp->data = val;
      temp->next = head;
      head = temp;
      listSize++;
    }

    void push_back(int val){
      Node *temp = new Node();
      temp->data = val;
      temp->next = NULL;
      
      if(head == NULL){
        head = temp;
      }
      else{
        Node *ptr = head;
        while(ptr->next != NULL) ptr = ptr->next;
        ptr->next = temp;
      }

      listSize++;
    }

    int pop_front(){
      if(!isEmpty()){
        Node *temp = head;
        int res = head->data;
        head = head->next;
        delete temp;
        listSize--;
        return res;
      }
      else
        throw string("List is empty!");
    }

  int pop_back(){
      if(!isEmpty()){
        int res;
        if(listSize > 1){
          Node *h = head;
          Node *f = head->next;
          while(f->next != NULL){
            h = h->next;
            f = f->next;
          }
          h->next = NULL;
          res = f->data;
          delete f;
          return res;
        }
        else{
          res = head->data;
          Node *temp = head;
          head = NULL;
          delete temp;
          return res;
        }

        listSize--;
        return res;
      }
      else
        throw string("List is empty!");
    }

    bool has(int data){
      for(Node *ptr = head; ptr != NULL; ptr=ptr->next){
        if(ptr->data == data)
          return true;
      }
      return false;
    }

    void print(){
      for(Node *ptr = head; ptr != NULL; ptr=ptr->next){
        cout << ptr->data << " ";
      }
      cout << endl;
    }
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

    // Linked List
    LinkedList *adjLL;

 
public:
    Graph(int v, int e);
 
    void addEdge(int start, int e);

    void showAdjLL();

    void DFS(int start);
};

Graph::Graph(int v, int e)
{
    this->v = v + 1;
    this->e = e + 1;

    this->adjLL = new LinkedList[this->v];
}


void Graph::addEdge(int start, int e)
{
    // Considering a directed graph
    adjLL[start].push_back(e);
}

void Graph::showAdjLL(){
  for(int i=1; i < v; i++){
    cout << i << " -> ";
    adjLL[i].print();
  }
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
                if(adjLL[nodeN].has(i) && !(processed[i]) && ready[i] && !(waiting[i])){
                    s.push(i);
                    processed[i] = true;
                    cout << nodeN << "->" << i << endl;
                }
            }
        }
    
}

Graph inputGraph(){
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

    return G;
}

int main(){
    Graph G = inputGraph();

    G.showAdjLL();

    int startingNode;
    
    cout<<"Starting node"<<endl;
    cin>>startingNode;
    cout<<"DFS traversal"<<endl;
    G.DFS(startingNode);

    return 0;
}
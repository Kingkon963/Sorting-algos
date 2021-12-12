#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) (for(int i=a;i<b;++i))
#define fr freopen("input.txt", 'r', stdin)
#define fw freopen("output.txt", 'w', stdout)

#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
#define CLS system("cls");
#define endl "\n"

struct Node{
    int data;
    Node *right;
    Node *left;
    Node *parent;
};

class BST{
    private:
        Node *root;
        void in_order(Node *node){
            if(node->left != NULL)
                in_order(node->left);

            cout << node->data << " ";

            if(node->right != NULL)
                in_order(node->right);
        }
        Node* getSuccessor(Node *start){
            Node* parent = start;
            Node* current = start->right;
            while(current != NULL){
                parent = current;
                current = current->left;
            } 
            return parent;
        }
    public:
        BST(){
            root = NULL;
        }
        BST(int data[], int len){
            root = NULL;
            for(int i = 0; i < len; i++){
                insert(data[i]);
            }
        }

        Node* insert(int data){
            Node *node = new Node();
            node->data = data;
            node->left = NULL;
            node->right = NULL;
            node->parent = NULL;

            Node *parent, *current;
            if(root == NULL){
                root = node;
                return root;
            }
            
            parent = NULL;
            current = root;
            while(current != NULL){
                parent = current;
                if(node->data < current->data)
                    current = current->left;
                else
                    current = current->right;
            }

            if(node->data < parent->data){
                parent->left = node;
                node->parent = parent;
            }
            else
                parent->right = node;
                node->parent = parent;
            
            return root;
        }

        Node* search(int data){
            Node* current = root;
            while(current != NULL){
                if(data < current->data)
                    current = current->left;
                else if(data > current->data)
                    current = current->right;
                else
                    break;
            }
            return current;
        }

        void deleteNode(int data){
            Node* node = search(data);
            if(node == NULL) return;

            enum NodeType {SingleChild, DoubleChild, LeafNode} nodeType;
            if((node->left == NULL && node->right != NULL) || (node->left != NULL && node->right == NULL))
                nodeType = SingleChild;
            else if(node->left != NULL && node->right != NULL)
                nodeType = DoubleChild;
            else 
                nodeType = LeafNode;
            cout << "Node Type: " << nodeType << endl;

            auto deleteLeaf = [](Node *node){
                if(node->data < node->parent->data)
                    node->parent->left = NULL;
                else
                    node->parent->right = NULL;
            };

            switch(nodeType){
                case LeafNode:
                    {   
                        deleteLeaf(node);
                    }
                    break;
                case SingleChild:
                    {
                        Node *child = (node->left != NULL) ? node->left : node->right;
                        if(node->data < node->parent->data){
                            node->parent->left = child;
                        }
                        else
                            node->parent->right = child;
                    }
                    break;
                case DoubleChild:
                    {
                        Node* successor = getSuccessor(node);
                        node->data = successor->data;
                        deleteLeaf(successor);
                    }
                    break;
                default:
                    cout << "Failed to delete!" << endl;
            }

        }
        
        void traverse(){
            in_order(this->root);
            cout << endl;
        }

        Node* getRoot(){
            return this->root;
        }
};

int main()
{
    FAST
    CLS
    int data[] = {8,3,1,6,7,4,10,14, 13};
    BST bst = BST(data, (sizeof(data)/sizeof(int)));
    bst.traverse();
    bst.deleteNode(3);
    Node *node = bst.search(3);
    if(node != NULL)
        cout << "Found! " << node->data << endl;
    else
        cout << "Not Found! " << endl;
    
    bst.traverse();

    return 0;
}
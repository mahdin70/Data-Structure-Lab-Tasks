#include<bits/stdc++.h>
using namespace std;

class node{
  public:
    int key;
    node *left;
    node *right;
  
    node(int n){
      key=n;
    }
};

class BST{
  public:
    node *root= NULL;

    void insert(int key){
        node *temp=new node(key);
        temp->left=NULL;
        temp->right= NULL;

        if(root==NULL){
            root=temp;
        }
        else{
            node *parent=root;
            node *prev= NULL;
            while(parent!=NULL){
                prev=parent;
                if(key>prev->key){
                    parent=parent->right;
                }
                else{
                    parent=parent->left;
                }
            }

            if(key>prev->key){
                prev->right=temp;
            }
            else{
                prev->left=temp;
            }
        }
    }

    node* minValueNode(node *Node) {     //finding out the inorder successor
        node *current = Node;
        while (current!=NULL && current->left != NULL){
            current = current->left;
        }
        return current;
    }

    node* deleteNode(node *temp, int key){
        if (temp == NULL){
            cout<<"No items are present to be deleted"<<'\n';
        }
        if(temp->key>key){
            temp->left=deleteNode(temp->left,key);
        }
        else if(temp->key<key){
            temp->right=deleteNode(temp->right,key);
        }
        else{
            if(temp->left ==NULL && temp->right==NULL){   //for the leaf
                return NULL;
            }
            else{
                if (temp->left == NULL) {
                    temp = temp->right;
                    temp->right=NULL;
                    return temp;
                }
                else if (root->right == NULL){
                    temp = temp->left;
                    temp->left =NULL;
                    return temp;
                }
                        
                node *temp1 = minValueNode(temp->right);  
                temp->key = temp1->key;
                temp->right=deleteNode(temp->right,temp1->key);
            }
            return temp;
        }
    }

    void levelorder(){
            queue<node*>levelorder_serials;
            levelorder_serials.push(root);
            while(!levelorder_serials.empty()){
                node *temp=levelorder_serials.front();
                if(temp->left !=NULL)
                    levelorder_serials.push(temp->left);
                if(temp->right != NULL)
                    levelorder_serials.push(temp->right);
                cout<<temp->key<<" ";
                levelorder_serials.pop();
            }
    }

};

int main(){
  BST bst;
  int n;
  cin >> n;
  while(n != -1){
    bst.insert(n);
    cin >> n;
  }
  bst.levelorder();
  int q;
  cin>>q;
  for(int i=0;i<q;i++){
    int t;
    cin>>t;
    bst.deleteNode(bst.root, t);
    bst.levelorder();
  }
  return 0;
}


#include<bits/stdc++.h>
using namespace std;

class node {
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
                 if(key-prev->key<=3){
                    cout<<"(Reservation failed)"<<" ";
                    return;
                 }
                 parent=parent->right;
               }

               else{
                 if(prev->key-key<=3){
                    cout<<"(Reservation failed)"<<" ";
                    return ;
                 }
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

    void inorder(){
        stack<node*>inorder_serials;  // stack of nodes 
        node *temp=root;

        while(temp!=NULL || !inorder_serials.empty()){
            if(temp!=NULL){
                inorder_serials.push(temp);
                temp=temp->left;
            }
            else{
                temp=inorder_serials.top();
                inorder_serials.pop();
                cout<<temp->key<<" ";
                temp=temp->right;
            }
        }
    }

    void levelorder(){//
        queue<node*>levelorder_serials;
        levelorder_serials.push(root);     //root is pushed to the queue

        while(!levelorder_serials.empty()){
            node *temp=levelorder_serials.front();     //temp is initialized by the front element of the queue which is root for the first element

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
  return 0;
}

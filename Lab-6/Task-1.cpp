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
    node *root= NULL;      //root initialized as NULL

    void insert(int key){
        node *temp=new node(key);
        
        temp->left=NULL;
        temp->right= NULL;

        if(root==NULL){
          root=temp;
        }
        else{
          node *parent=root;    //parent holds the root pointer
          node *prev= NULL;     

          while(parent!=NULL){
            prev=parent;
            
            if(key > prev->key){
              if((key - prev->key)<=3){
                  cout<<"(Reservation failed)"<<" ";
                  return;
              }
              parent=parent->right;
            }

            else{
              if(prev->key - key<=3){
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
        stack<node*>inorder_serials;
        node *temp=root;                         //temp is initialized by root

        while(temp!=NULL || !inorder_serials.empty()){
            if(temp!=NULL){
                inorder_serials.push(temp);      //pushing left to the stack untill null encountered
                temp=temp->left;                 //set temp to temp->left
            }
            else{
                temp=inorder_serials.top();      //when temp is not null , printing started
                inorder_serials.pop();
                cout<<temp->key<<" ";
                temp=temp->right;
            }
        }
    }
};


int main(){
  BST bst;
  int n;
  cin >> n;
  while(n != -1){
    bst.insert(n);
    bst.inorder();
    cin >> n;
  }
   return 0;
}

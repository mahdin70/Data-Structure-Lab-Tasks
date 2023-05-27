#include<bits/stdc++.h>
using namespace std;

class node {
  public:
    int key;
    node *parent;
    node *left;
    node *right;
  
    node(int n){
      key=n;
    }
};

class BST{
  public:
    node *root= NULL;
    void insert_value(int key){
        node *temp=new node(key);
        temp->left=NULL;
        temp->right= NULL;
        temp->parent=NULL;
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
              temp->parent=prev;
          }
          else{
              prev->left=temp;
              temp->parent=prev;
          }
       }
    }

    int max_in_between(int LowLimit,int HighLimit){
        node *temp=root;
        int max_val=LowLimit;
        while(temp->key!=LowLimit){    //tracing the lower limit in the tree
            if(temp->key>LowLimit){
                if(temp->left==NULL)
                   break;
                else 
                   temp=temp->left;
            }
            else{
                if(temp->right==NULL)
                   break;
                temp=temp->right;
            }
        }

        node *temp2=temp;
        while(temp!=NULL && temp->key!=HighLimit){ //tracing the higher limit in the right of the Low Limit
            temp=temp->right;
        }

        if(temp!=NULL){
             max_val=max(max_val,temp->key);
             return max_val;
        }

        else{
             max_val=LowLimit;
             while(temp2->parent !=NULL && temp2->parent->key<=HighLimit){ 
                temp2=temp2->parent;
                max_val=max(max_val,temp2->key);
             }
             while(temp2!=NULL && temp2->key<HighLimit){  //checking if the temp2->key is less than the High limit
                temp2=temp2->right;
                max_val=max(max_val,temp2->key);
              }
             return max_val;
        }
    }
};

int main(){
  BST bst;
  int n;
  cin >> n;
  while(n != -1){
    bst.insert_value(n);
    cin >> n;
  }
  int q;
  cin>>q;
  for(int i = 0; i < q; i++){
    int LowLimit,HighLimit;
    cin >> LowLimit>>HighLimit;
    cout << bst.max_in_between(LowLimit,HighLimit)<< endl;
  }
  return 0;
}
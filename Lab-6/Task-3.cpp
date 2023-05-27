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
        node *temp = new node(key);
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

    void levelOrder(){
        queue<node*>levelorder_serials;
        levelorder_serials.push(root);

        int height=0;
        bool flag = false;

        while(!levelorder_serials.empty()){
            node *temp=levelorder_serials.front();
            if(temp->left !=NULL){
                levelorder_serials.push(temp->left);
                if(!flag){
                    height++;
                    flag=true;        //flag is maintained to keep track of the same level
                }
            }
            if(temp->right != NULL){
                levelorder_serials.push(temp->right);
                    if(!flag){
                        height++;
                    }
                    flag=false;
            }
            levelorder_serials.pop();
        }
        cout<<height<<'\n';
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
  bst.levelOrder();
  return 0;
}
#include<bits/stdc++.h>
using namespace std;

class node{
  public:
    int key;
    node *left;
    node *right;
    int visit;
  
    node(int n){
      key=n;
      visit=0;
    }
};

class BST{
  public:
    node *root= NULL;

    void insert_value(int n){
        if(root == NULL){
            node* dummy = new node(n);
            dummy->left = NULL;
            dummy->right= NULL;
            root = dummy;
        }
        else{
            recursiveInsertion(root, n);
        }
    }

    void recursiveInsertion(node* Node, int n){
        node* dummy = new node(n);
        dummy->left = NULL;
        dummy->right= NULL;
        if(n > Node->key){
            Node->visit++;
            if(Node->right == NULL){
                Node->right = dummy;
            }
            else{
                recursiveInsertion(Node->right, n);
            }
        }

        else{
            Node->visit++;
            if(Node->left == NULL){
                Node->left = dummy;
            }
            else{
                recursiveInsertion(Node->left, n);
            }
        }
    }

    void inorder(node *temp){
        if(temp==NULL)
          return;
        else{
          inorder(temp->left);
          cout<<temp->key<<" "<<temp->visit<<" "<<"\n";
          inorder(temp->right);
        }
    }


    void PreviousNodeNumber(int n,node *temp, int& num){
        if(n> temp->key){
            if(temp->left!=NULL){
                num=num+temp->left->visit+2;
            }
            else 
                num++;
            PreviousNodeNumber(n,temp->right,num);
        }

        else if(n<temp->key){
            PreviousNodeNumber(n,temp->left,num);
        }

        else{
            if(temp->left != NULL){
                num = num + temp->left->visit + 1;
            }
        }
    }

    int previous_node_encountered(int number){
        int num=0;
        PreviousNodeNumber(number, root,num);
        return num;
    }
};


int main(void){
  BST bst;
  int n;
  cin >> n;

  while(n != -1){
    bst.insert_value(n);
    cin >> n;
  }
  bst.inorder(bst.root);

  int q;
  cin>>q;

  for(int i = 0; i < q; i++){
    int t;
    cin >> t;
    cout << bst.previous_node_encountered(t) << endl;
  }
  return 0;
}

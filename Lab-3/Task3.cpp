#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size){
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++){
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    return head;
}

void printList(Node* n)
{
    while(n!=NULL){
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int length(Node* head){
    Node *curr = head;

    int count = 0;
    while(curr != NULL)
    {
        curr = curr->next;
        count++;
    }
    return count;
}

class Solution{
    public:
    void ReturnHalf(struct Node* head){
       Node *first = head;
       Node *second = head;
   
       int n;
       int halfLen = length(head);
       if(halfLen%2 == 0){
            n = halfLen/2;
       }
       else{
            n = (halfLen/2) +1;
       }
   
       for(int i=0; i<n; i++){
           first = first->next;
       }   
       while(first != NULL){
           second = second->next;
           first = first->next;
       }
       printList(second);
    }
};

int main(){
    cout << "Size: ";
    int size;
    cin >> size;

    Node* head = buildList(size);            
    Solution object;
    object.ReturnHalf(head);

    return 0;
}

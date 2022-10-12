#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node *head = NULL;
Node *tail = NULL;

void PushBack(int x){
    if(head == NULL){
        Node *temp = new Node(x);
        head = temp;
        tail = temp;
    }

    else{
        Node *temp = new Node(x);
        tail->next = temp;
        tail = temp;
    }          
}

void PopBack(){
    Node* second_last = head;

    while (second_last->next->next != NULL) //The Last that we are going to pop
       second_last = second_last->next;
    delete(second_last->next);
    second_last->next = NULL;
}

void display(){
    Node *n = head;
    while(n!=NULL){
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

void Reverse(){
    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;
        
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

int main()
{
    PushBack(10);
    PushBack(20);
    PushBack(30);
    PushBack(40);
    PushBack(50);
    PushBack(60);

    display();
    Reverse();
    display();

    PopBack();
    display();

    PopBack();
    display();

    return 0;
}



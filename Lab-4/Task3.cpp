#include <bits/stdc++.h>
using namespace std;
// Push into the Stack
queue<int>q;

void push_s(int x) {
    queue<int>q1;    //taking a new queue q1 to insert q 
    while(!q.empty()){
        q1.push(q.front()); //q is inserting into q1 in the backward order
        q.pop();
    }
    q.push(x);
    while(!q1.empty()){
        q.push(q1.front());
        q1.pop();
    }
}

// Removes the element on top of the stack.
void pop_s() {
        q.pop();
}
// Get the top element.
int top_s() {
    return q.front();
}
// Return whether the stack is empty.
bool empty_s() {
    if(q.empty())
      return true;
    else 
      return false;
}

int main() {

    push_s(10);
    cout <<top_s()<<endl;
    push_s(20);
    cout <<top_s()<<endl;
    pop_s();
    cout <<top_s()<<endl;
    push_s(100);
    cout <<top_s()<<endl;
    cout <<empty_s()<<endl;
    pop_s();
    pop_s();
    cout <<empty_s()<<endl;
    return 0;

}

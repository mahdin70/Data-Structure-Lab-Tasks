#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    queue<int>q;            //Students in Queue
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        q.push(k);
    }
    stack<int>s;            //Sandwich in Stack
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=n-1;i>=0;i--){ //Rearranging the order, as I take input in the array
        s.push(arr[i]);
    }
    
    int prev =0; //how many students are going to the end of the line
    while(!s.empty() && prev!=n){  //The loop will run : untill the queue empty or there is someone to eat the food
        if(s.top()==q.front()){ //If the front of queue and and the top stack matches, both will be popped
            s.pop();
            q.pop();
            prev = 0;
            n--;
        }
        else{
            int r = q.front(); //Move the front to the back if doesn't match 
            q.pop();
            q.push(r);
            prev++;
        }
    }
    cout<<q.size()<<'\n';
    return 0;
}

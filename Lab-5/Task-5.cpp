#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int>stones;
    int k;
    cin>>k;
    while(k!=-1){
        stones.push(k);
        cin>>k;
    }
    
    while(stones.size()>1){
        int stone1=stones.top();
        stones.pop();
        if(stone1==stones.top()){
            stones.pop();
        }
        else{
            stones.push(stone1-stones.top());
            stones.pop();
        }
    }
    if(stones.empty())
       cout<<0<<'\n';
    else 
       cout<<stones.top()<<'\n';
    return 0;
}

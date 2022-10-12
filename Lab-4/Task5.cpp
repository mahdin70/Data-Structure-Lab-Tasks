#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    queue<int>q;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        q.push(k);
    }
    stack<int>s;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=n-1;i>=0;i--){
        s.push(arr[i]);
    }
    int pr=0;
    while(!s.empty() && pr!=n){
        if(s.top()==q.front()){
            s.pop();
            q.pop();
            pr=0;
            n--;
        }
        else{
            int r=q.front();
            q.pop();
            q.push(r);
            pr++;
        }
    }
    cout<<q.size()<<'\n';
    return 0;
}

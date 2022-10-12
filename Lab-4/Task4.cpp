#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    queue<int>q;
    while(n!=-1){
        q.push(n);
        cin>>n;
    }
    int k;
    cin>>k;
    int si=q.size();
    int num =k;
    int r;
    int ans=0;
    while(num>=0){
        r=q.front();
        q.pop();
        q.push(r-1);
        ans++;
        num--;
    }
    while(!q.empty()){
         if(q.front()>=r){
            ans=ans+r-1;
         }
         else{
            ans=ans+q.front();
         }
         q.pop();
    }
    cout<<ans<<'\n';
    return 0;
}

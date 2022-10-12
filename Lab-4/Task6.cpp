#include <bits/stdc++.h>

using namespace std;

int main()
{
    queue<int>q;
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        q.push(i);
    }
    while(q.size()>1){
        int p=0;
        int r;
        while(p<k-1){
                r=q.front();
                q.pop();
                q.push(r);
                p++;
        }
        q.pop();
    }
    cout<<q.front()<<'\n';
    return 0;
}

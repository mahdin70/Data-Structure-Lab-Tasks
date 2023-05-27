#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    queue<int>q;    //passenger with required number of tickets
    while(n!=-1){   
        q.push(n);  //input taking 
        cin>>n;
    }

    int k;
    cin>>k;

    int num =k;  //desired position
    int r;   
    int ans=0;

    while(num >= 0){  
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

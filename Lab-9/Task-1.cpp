#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<int,bool> mp;
    int k;
    cin>>k;
    while(k!=-1){
        mp[k]=true;
        cin>>k;
    }
    
    int p;
    cin>>p;
    bool flag=false;
    while(p!=-1){
        if(!mp[p]){
            flag=true;
        }
        cin>>p;
    }

    if(flag){
        cout<<"No"<<endl;;
    }
    else{
        cout<<"Yes"<<endl;
    }
}
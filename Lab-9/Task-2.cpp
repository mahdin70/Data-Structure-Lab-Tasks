#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<int,int> mp;
    vector<int> v;
    int k;
    cin >> k;
    while(k!=-1){
        v.push_back(k);
        cin >> k;
    }
    int target;
    cin >> target;
    for(int i = 0 ; i < v.size();i++){
        mp[v[i]]++;
    }

    vector<pair<int,int>> answers;
    for(int i = 0; i<v.size();i++){
        pair<int,int> ans ;
        if(mp[v[i]] > 0){
            ans.first = v[i];
        }
        if(mp[target - v[i]] > 0){
            ans.second = target - v[i];
            mp[target - v[i]]--;
            answers.push_back(ans);
        }
        mp[v[i]]--;
    }
    for(auto a : answers){
        cout<<"("<<a.first<<","<<a.second<<")"<<" ";
    }
    if(answers.size()==0){
        cout<<"No Pairs Found"<<'\n';
    }
    return 0;
}

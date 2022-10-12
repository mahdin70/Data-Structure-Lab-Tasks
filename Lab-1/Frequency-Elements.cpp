#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, count;
    
    cout << "Size: ";
    cin >> n;
    int array[n];

    for(int i=0; i<n; i++){
        cin >> array[i];
    }
    
    map<int,int> freq;
    
    for(int i=0; i<n; i++){
        freq[array[i]]++;
    }
    
    for(auto x: freq){
        cout << x.first << " Occurs : " << x.second <<" times"<< endl;
    }
    return 0;
}
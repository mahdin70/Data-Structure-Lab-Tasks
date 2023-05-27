#include <bits/stdc++.h>
using namespace std;
queue<int>q;

int ping(int t) {
    q.push(t);
    while((t-q.front())>3000){ //Checking if the difference between front and rear element is 3000 or not , if 3000 then pop
        q.pop();
    }
    return q.size();
}
int main() {
    cout<<ping(1)<<'\n';
    cout<<ping(2)<<'\n';
    cout<<ping(3)<<'\n';
    cout<<ping(4)<<'\n';
    cout<<ping(3001)<<'\n';
    cout<<ping(3002)<<'\n';
    cout<<ping(3003)<<'\n';
    cout<<ping(6003)<<'\n';
    cout<<ping(10003)<<'\n';

    return 0;
}

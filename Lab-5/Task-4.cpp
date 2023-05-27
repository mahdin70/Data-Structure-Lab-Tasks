#include <bits/stdc++.h>
using namespace std;

int main()
{
    int number_of_meeting;
    cin>>number_of_meeting;

    priority_queue<pair<int,bool>>schedules;

    for(int i=0;i<number_of_meeting;i++){
        int starting,ending;
        cin>>starting>>ending;

        pair<int,bool>start;
        start.first=starting;
        start.second=true;
        schedules.push(start);

        pair<int,bool>finish;
        finish.first=ending;
        finish.second=false;
        schedules.push(finish);
    }

    int max_room=0;
    int room=0;

    stack<pair<int,bool>>serials;

    while(!schedules.empty()){
        serials.push(schedules.top());
        schedules.pop();
    }

    while(!serials.empty()){
        if(serials.top().second){
            room++;
            max_room= max(max_room,room);
        }
        else{
            room--;
        }
        serials.pop();
        cout<<max_room<<'\n';
    }
    cout<<max_room<<'\n';
    return 0; 
}

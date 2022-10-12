#include<bits/stdc++.h>
using namespace std;

int BinarySearch(vector<int> arr,int size,int key){
    int start = 0;
    int end = size-1;
    int mid = start + (end-start)/2;
 

    while(start<=end){
        if(arr[mid] == key){
            return mid;
        }
        if(key > arr[mid]){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
        mid = start+(end-start)/2;
    }
    return -1;
}


int main(){
    int size = 0;
    int x;
    vector<int> v1;

    while(cin>>x){
        if(x>=0){
            v1.push_back(x);
            size++;
        }
        else{
            break;
        }
    }
    
    int value;
    cin >> value;

    int index = BinarySearch(v1,size,value);
    cout<< index <<endl;
    
    return 0;
}
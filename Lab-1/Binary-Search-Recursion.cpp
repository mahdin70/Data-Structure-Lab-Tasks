#include <bits/stdc++.h>
using namespace std;

int BinarySearch(vector<int> arr, int num, int beg, int end){
  int mid;
  if (beg > end){
    cout << "-1";
    return 0;
  } 
  else{
    mid = (beg + end) / 2;
    if(arr[mid] == num){
      cout<< mid <<endl;
      return 0;
    } 
    else if (num > arr[mid]){
      BinarySearch (arr, num, mid+1, end);
    } 
    else if (num < arr[mid]){
      BinarySearch (arr, num, beg , mid-1);
    }
  }
}
 
int main(){
  int num, i,beg, end;
  int n = 0;
  int x;
  vector<int> v1;
  while(cin>>x){
    if(x>=0){
      v1.push_back(x);
      n++;
    }
    else{
      break;
    }
  }
  cin >> num;
  beg = 0;
  end = n-1;
 
  BinarySearch (v1, num, beg, end);
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;
void Swap_it(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int arr[],int n,int i){
            int smallest=i;
            if((2*i+1)<n && arr[2*i+1]<arr[smallest]){
                smallest=2*i+1;
            }
            if((2*i+2)<n && arr[2*i+2]<arr[smallest]){
                smallest=2*i+2;
            }
            if(smallest!=i){
                Swap_it(&arr[i],&arr[smallest]);
                heapify(arr,n,smallest);
            }
}
void build_min_heap(int arr[],int n){
        for(int i=(n/2)-1;i>=0;i--){
            heapify(arr,n,i);
        }
}
void pop_head(int arr[],int n){
        Swap_it(&arr[0],&arr[n-1]);
        n--;
        build_min_heap(arr,n-1);
}
void Push(int arr[],int n,int number){
        arr[n]=number;
        build_min_heap(arr,n+1);
}

int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    build_min_heap(arr,n);
    int ans=0;
    while(arr[0]<k){
            int sk=arr[0];
            pop_head(arr,n);      ///taking the lowest value and removing it
            n--;                  /// length decreases
            int rk=arr[0];        /// taking the second lowest value
            pop_head(arr,n);      ///removing it
            n--;                  ///length decreases
            Push(arr,n,1*sk+2*rk);  ///lowest value= lowest value+2*second_lowestvalue
            n++;
            ans++;
    }
    cout<<ans<<'\n';
    return 0;
}

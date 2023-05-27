#include <bits/stdc++.h>
using namespace std;

void Swap_it(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[],int n,int i){
            int largest=i;
            if((2*i+1)<n && arr[2*i+1]>arr[largest]){ //comparing to left child
                largest=2*i+1;
            }
            if((2*i+2)<n && arr[2*i+2]>arr[largest]){ //comparing to right child
                largest=2*i+2;
            }
            if(largest!=i){   //swapping between child and parent if any child is greater
                Swap_it(&arr[i],&arr[largest]);
                heapify(arr,n,largest);
            }
}

void build_max_heap(int arr[],int n){
        for(int i=n/2-1;i>=0;i--){   //n/2 can be the last possible parent
            heapify(arr,n,i);
        }
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<'\n';
}

void heap_sort(int arr[],int n){
        for(int i=n-1;i>=0;i--){
            Swap_it(&arr[i],&arr[0]);
            heapify(arr,i,0);
        }      
            //Swapping in reverse order 
            reverse(arr,arr+n);       
}

int main(){

    int arr[100];
    int i;
    
    for(i=0;;i++){
        int k;
        cin>>k;
        if(k==-1)
          break;
        else 
          arr[i]=k;
    }

    build_max_heap(arr,i);
    heap_sort(arr,i);
    for(int k=0;k<i;k++){
        cout<<arr[k]<<" ";
    }
    cout<<'\n';
    return 0;
}

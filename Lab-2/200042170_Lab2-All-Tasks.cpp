#include<bits/stdc++.h>
using namespace std;


class Dynamic_Array{
    public:
    int Size;
    int Capacity;
    int *arr;
    Dynamic_Array(){
        Size = 0;
        Capacity = 1;
        arr = new int[Capacity];
    }

    int Get(int i){
        if ((i < 0 ) or (i >= Size)){
            cout << "Index out of Range" << endl;
            return -1;
        }
        return arr[i];
    }

    void Set(int i,int val){
        if ((i < 0 ) or (i >= Size)){
            cout << " Index out of Range" << endl;
            return;
        }
        arr[i] = val;
    }

    void Reverse(){
       int *temp = new int[Size];
       for(int i = Size-1,j = 0 ; i >= 0 ; i--){
        temp[j++] = arr[i];
       }
       delete[] arr;
       arr = temp;
    }

    void PushBack(int val){
        if(Size>=Capacity){
            Capacity = Capacity*2;
            int *newarr;
            newarr = new int[Capacity];
            for(int i = 0 ; i < Size ; i++){
                newarr[i]=arr[i];
            }
            delete []arr;
            arr = newarr;
        }
        arr[Size] = val;
        Size++;
    }

    int Get_Size(){
        return Size;
    }

    int Get_Capacity(){
        return Capacity;
    }
};

void RemoveOccurs(Dynamic_Array arr,int val){
        
        int cnt = 0;
        int size = arr.Get_Size();
        int i;


        for(i = 0; i < size; i++){
            if(arr.Get(i) == val)
            cnt++;
        }


        int new_arr[(size - cnt)];


        int ind = 0;
        for(i = 0; i < size; i++){
            if(arr.Get(i) != val){
                new_arr[ind] = arr.Get(i);
                ind++;
            }
        }


        int sz = (sizeof(new_arr)/sizeof(new_arr[0]));


        for(i = 0; i < size; i++){
            cout << new_arr[i] << " ";
        }


    return;
}


void NewRemove(Dynamic_Array arr , int val){
    
    int s = arr.Get_Size();
    int count=0;
    int i;


    for(i=0;i<s;i++){
        if(arr.Get(i)==val){
            count++;
        }
    }


    int *newarr = new int[s - count];
    for(int i=0;i<s-count;i++){
        if(newarr[i]==val){
            continue;
        }
        cout<<newarr[i]<<" ";
    }
}


int main(){
    Dynamic_Array arr;
    for(int i =0;i<16;i++){
        arr.PushBack(100 + i);
    }


    for(int i = 0; i < arr.Get_Size();i++){
        cout << arr.Get(i)<<" ";
    }


    cout <<"\n";


    arr.Reverse();


    for(int i = 0; i < arr.Get_Size();i++){
        cout << arr.Get(i)<<" ";
    }




// Task : 2 :


    Dynamic_Array arr2;


    arr2.PushBack(0);
    arr2.PushBack(1);
    arr2.PushBack(2);
    arr2.PushBack(2);
    arr2.PushBack(3);
    arr2.PushBack(0);
    arr2.PushBack(4);
    arr2.PushBack(2);


    cout<<"\n\n";
    cout<<"Task-2 :"<<endl;


    for(int i = 0; i < arr2.Get_Size();i++){
        cout << arr2.Get(i)<<" ";
    }
    cout<<"\n\n";
    
    RemoveOccurs(arr2,2);


 
    Dynamic_Array arr3;


    arr3.PushBack(0);
    arr3.PushBack(2);
    arr3.PushBack(5);
    arr3.PushBack(3);
    arr3.PushBack(4);
    arr3.PushBack(2);
    arr3.PushBack(4);
    arr3.PushBack(2);


    cout<<"\n\n";
    cout<<"Bonus Task:"<<endl;


    for(int i = 0; i < arr3.Get_Size();i++){
        cout << arr3.Get(i)<<" ";
    }
    cout<<"\n\n";
    
    NewRemove(arr3,2);


}
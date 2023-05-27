#include <bits/stdc++.h>
using namespace std;

class CircularQueue{
private:
        int Front;
        int Rear;
        int arr[10];
public:
        Queue(){
            Front =-1;
            Rear =-1;
        }
        bool IsFull(){
            if(Front==0 && Rear==9){  
                return true;
            }
            else if(Front==Rear+1){   //front and rear is the adjacent position in circular queue
                return true;
            }
            else{
                return false;
            }
        }

        bool IsEmpty(){
            if(Front==-1){
                return true;
            }
            else{
                return false;
            }
        }

        void EnQueue(int k){
                if(IsEmpty()){
                    Front++;
                    Rear =(Rear+1)%10;    // When the Queue is empty the front is increamented to 0 that is Front++ ,and also the Rear is also increamented to 0 but after this small operation
                    arr[Rear]=k;
                }
                else if (IsFull()){
                    cout<<"Full"<<'\n';
                }
                else{
                     Rear =(Rear+1)%10;  // Same thing as previous
                     arr[Rear]=k;
                }
        }
        void DeQueue(){
                if(IsEmpty()){
                    cout<<"Empty"<<'\n';
                }
                else{
                    Front=(Front+1)%10; // Changing the front index to the next one
                }
        }
        void ShowFront(){
                cout<<"Front"<<arr[Front]<<'\n';
        }
        void ShowRear(){
                cout<<"Rear"<<arr[Rear]<<'\n';
        }
};

int main(){
    CircularQueue q;
    for(int i=1;i<10;i++){
            q.EnQueue(i);
    }
    for(int i=0;i<10;i++){
        q.ShowFront();
        q.ShowRear();
        q.DeQueue();
        q.EnQueue(i);
    }
    return 0;
}

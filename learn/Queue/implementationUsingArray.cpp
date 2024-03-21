#include<bits/stdc++.h>
using namespace std;

// Naive Queue implementation //
class myQueue{
    private:
        int n;
        int *arr;
        int size;
        
        
        bool isFull(){
            if(size == n){
                return true;
            }
            return false;
        }

        bool isEmpty(){
            if(size == 0){
                return true;
            }
            return false;
        }

    public:
        myQueue(int n){
            this->n = n;
            size = 0;
            arr = new int[n];
        }

        void enQue(int x){
            if(isFull()){return;}
            arr[size] = x;
            size++;
        }
        void deque(){
            if(isEmpty()){
                return;
            }
            for(int i = 1 ; i<size ; i++){
                arr[i-1] = arr[i];
            }
            size--;
        }

        int getFront(){
            if(isEmpty()){
                return -1;
            }
            return arr[0];
        }
        int getRearer(){
            if(isEmpty()){
                return -1;
            }
            return arr[size-1];
        }
};

// Efficient Queue Implementation //

class Queue{
    private:
        int cap , size , front , *arr;
    public:
        Queue(int n){
            cap = n;
            size = 0;
            front = 0;
            arr = new int[cap];
        }
        bool isEmpty(){
            if(size == 0){
                return true;
            }
            return false;
        }
        bool isFull(){
            if(size == cap){
                return true;
            }
            return false;
        }

        int getFront(){
            if(isFull()){
                return -1;
            }
            return front;
        }

        int getRearer(){
            if(isEmpty()){
                return -1;
            }
            return (front + size - 1)%cap;
        }
        void enque(int x){
            if(isFull()){
                return;
            }
            int rearer = getRearer();
            rearer = (rearer + 1)%cap; // yeh Kyu?? //
            arr[rearer] = x;
            size++;
        }
        void deque(){
            if(isEmpty()){
                return;
            }
            front = (front + 1)%cap;
            size--;
        }
};


int main(){
     
    Queue mq(5);
    
    mq.enque(10);
    mq.enque(20);
    mq.enque(30);
    cout<<mq.getFront()<<endl;
    mq.deque();
    cout<<mq.getFront()<<endl;
    cout<<mq.getRearer()<<endl;


    return 0;
}
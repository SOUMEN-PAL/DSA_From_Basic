#include<bits/stdc++.h>
using namespace std;


// Array based approach //
class MyDeque{
    private:
        int size , cap , *arr;
    public:
        MyDeque(int c){
            cap = c;
            size = 0;
            arr = new int[cap];
        }
        bool isEmpty(){
            return size == 0;
        }
        bool isFull(){
            return size == cap;
        }

        void insertRear(int x){
            if(isFull()){
                return;
            }
            arr[size] = x;
            size++;
        }
        void deleteRear(){
            if(isEmpty()){
                return;
            }
            size--;
        }

        void insertFront(int x){
            if(isFull()){
                return;
            }
            for(int i = size - 1 ; i>=0 ; i--){
                arr[i+1] = arr[i];
            }
            arr[0] = x;
            size++;
        }

        void deteleFront(){
            if(isEmpty()){
                return;
            }
            for(int i = 0 ; i<size - 1 ; i++){
                arr[i] = arr[i+1];
            }
            size--;
        }

        int getFront(){
            if(isEmpty()){
                return -1;
            }
            return arr[0];
        }

        int getRear(){
            if(isEmpty()){
                return -1;
            }
            return arr[size - 1];
        }

        int Size(){
            return size;
        }

};

//Circular array based implementation //
class myDque{
private:
    int front, size, cap, *arr;
public:
    myDque(int c){
        cap = c;
        size = 0;
        front = 0;
        arr = new int[cap];
    }
    
    bool isEmpty(){
        return size == 0;
    }

    bool isFull(){
        return size == cap;
    }

    int getFront(){
        if(isEmpty()){
            return -1;
        }
        return arr[front];
    }

    int getRear(){
        if(isEmpty()){
            return -1;
        }
        return arr[(front + size - 1) % cap];
    }

    void insertFront(int x){
        if(isFull()){
            std::cout << "Deque is full, cannot insert at front." << std::endl;
            return;
        }
        front = (front - 1 + cap) % cap; // Calculate new front index
        arr[front] = x;
        size++;
    }

    void insertRear(int x){
        if(isFull()){
            std::cout << "Deque is full, cannot insert at rear." << std::endl;
            return;
        }
        int new_rear = (front + size) % cap;
        arr[new_rear] = x;
        size++;
    }
    
    void deleteFront(){
        if(isEmpty()){
            std::cout << "Deque is empty, cannot delete from front." << std::endl;
            return;
        }
        front = (front + 1) % cap;
        size--;
    }

    void deleteRear(){
        if(isEmpty()){
            std::cout << "Deque is empty, cannot delete from rear." << std::endl;
            return;
        }
        size--;
    }

    ~myDque() {
        delete[] arr;
    }
};

int main() {
    myDque dq(5);
    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertFront(5);
    // dq.deleteRear();
    dq.deleteFront();
    std::cout << "Front: " << dq.getFront() << std::endl;
    std::cout << "Rear: " << dq.getRear() << std::endl;
    return 0;
}
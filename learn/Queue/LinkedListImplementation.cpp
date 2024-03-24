#include<bits/stdc++.h>
using namespace std;

// Define Node structure
class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int d) {
        data = d;
        next = NULL;
    }
};

class myQueue{
    private:
        int size;
        Node *front , *rear;
    public:
        myQueue(){
            front = rear = NULL;
            size = 0;
        }

        bool isEmpty(){
            if(size == 0){
                return true;
            }
            return false;
        }
        void enque(int x){
            Node * temp = new Node(x);
            if(front == NULL){
                front = rear = temp;
            }
            else{
                rear->next = temp;
                rear = temp;  
            }
            size++;
        }

        void dequeue(){
            if(isEmpty()){
                return;
            }
            Node * temp = front;
            front = front->next;
            delete(temp);
            size--;
        }

        int getFront(){
            if(isEmpty()){
                return -1;
            }
            return front->data;
        }
        int getRearer(){
            if(isEmpty()){
                return -1;
            }
            return rear->data;
        }
};

int main(){
    
    myQueue mq;
    mq.enque(10);
    mq.enque(20);
    mq.enque(30);
    mq.dequeue();
    mq.dequeue();
    mq.dequeue();
    cout<<mq.getFront()<<" "<<mq.getRearer()<<endl;


    
    return 0;
}
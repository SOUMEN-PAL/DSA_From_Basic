#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
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
        int Size(){
            return size;
        }
};

int main(){
    
    myQueue mq;
    mq.enque(10);
    mq.enque(20);
    mq.enque(30);
    cout<<mq.Size()<<endl;
    mq.dequeue();
    mq.dequeue();
    mq.dequeue();
    cout<<mq.getFront()<<" "<<mq.getRearer()<<endl;


    
    return 0;
}
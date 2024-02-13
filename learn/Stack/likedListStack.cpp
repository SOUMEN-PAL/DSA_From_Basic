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


class myStack{

    private:
        Node *head;
        int sz;
    public:
        myStack(){
            head = NULL;
            sz = 0;
        }

        void push(int x){
            Node *temp = new Node(x);
            temp->next = head;
            head = temp;
            sz++;
        }

        int pop(){
            if(head == NULL){
                cout<<"Underflow"<<endl;
                return INT_MAX;
            }
            int res = head->data;
            Node *temp = head;
            head = head->next;
            delete (temp);// before moving in the local sets it was 
            sz--;
            return res;
        }

        void seek(){
            if(head == NULL){
                cout<<"Empty stack No element"<<endl;
                return;
            }
            cout<<head->data<<endl;
        }

        int size(){
            return sz;
        }

        bool isEmpty(){
            return head == NULL;
        }

};


int main(){

    myStack s;
    
    s.push(10);
    s.push(20);

    s.pop();
    s.pop();
    s.seek();
    cout<<s.size();
    return 0;
}
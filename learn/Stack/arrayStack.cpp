#include<bits/stdc++.h>
using namespace std;

class Mystack{
    private:
        int *arr;
        int cap;
        int top;
    public:
        Mystack(int d){
            cap = d;
            arr = new int[d];
            top = -1;
        }

        void push(int d){
            if(top<cap-1){
                top++;
                arr[top] = d;
            }
            else{
                cout<<"Overflow"<<endl;
            }
        }

        int pop(){
            if(top != -1){
                int res = arr[top];
                top--;
                return res;
            }
            else{
                cout<<"UnderFlow"<<endl;
                return -1;
            }
        }

        void seek(){
            cout<<arr[top]<<endl;
        }

        int size(){
            return top + 1;
        }

        bool isEmpty(){
            return top == -1;
        }
};


int main(){
    
    Mystack s(5);

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.seek();
    
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

// Fixed Array Stack //
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


// Dynamic Array Stack //
class myStack{
    private:
        vector<int> arr;

    public:
        
        void push(int d){
            arr.emplace_back(d);
        }

        int pop(){
            int res = arr.back();
            arr.pop_back();
            return res;
        }

        void seek(){
            cout<<arr.back()<<endl;
        }

        void size(){
            cout<<arr.size()<<endl;
        }

        bool isEmpty(){
            return arr.empty();
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


    myStack st;
    st.push(10);
    st.seek();
    
    return 0;
}
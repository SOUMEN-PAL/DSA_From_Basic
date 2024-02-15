#include<bits/stdc++.h>
using namespace std;

class myStack{
    private:
        int *arr;
        int cap1;
        int cap2;
        int top1;
        int top2;
    public:
    // constructors //
        myStack(int size_1 , int size_2){
            cap1 = size_1;
            cap2 = size_2;
            arr = new int[cap1 + cap2];
            top1 = -1;
            top2 = cap1-1;
        }
    // Utility function //    
        void push1(int x){
            if(top1 == cap1){
                cout<<"Overflow"<<endl;
                return;
            }
            top1++;
            arr[top1] = x;
        }

        void push2(int x){
            if(top2 == cap1 - 1 + cap2){
                cout<<"Overflow"<<endl;
                return;
            }
            top2++;
            arr[top2] = x;
        }

        int pop1(){
            if(top1 == -1){
                cout<<"Under flow"<<endl;
                return INT_MAX;
            }
            else{
                int res = arr[top1];
                top1--;
                return res;
            }
        }

        int pop2(){
            if(top2 == cap1-1){
                cout<<"Under flow stack2"<<endl;
                return INT_MAX;
            }
            else{
                int res = arr[top2];
                top2--;
                return res;
            }
        }

        int seek1(){
            if(top1 == -1){
                cout<<"Empty pe seek mar raha ha"<<endl;
                return INT_MAX;
            }
            return arr[top1];
        }
        int seek2(){
            if(top2 == cap1 - 1){
                cout<<"Empty pe seek mar raha ha"<<endl;
                return INT_MAX;
            }
            return arr[top2];
        }

        int size1(){
            return top1 + 1;
        }
        int size2(){
            return top2 + 1;
        }

        bool isEmpty1(){
            return top1 == -1;
        }
        bool isEmpty2(){
            return top2 == cap1 - 1;
        }


};



int main(){
    
    myStack s(4 , 1);
    s.push1(10);
    s.push1(20);
    s.push2(30);
    s.pop2();
    s.pop2();

    cout<<s.seek1()<<endl;
    cout<<s.seek2()<<endl;

    return 0;
}
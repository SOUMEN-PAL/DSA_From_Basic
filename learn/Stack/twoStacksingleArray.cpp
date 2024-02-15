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

// second Implementation //
class myStack2{
    private:
        int cap;
        int *arr;
        int top1 , top2;

    public:
        myStack2(int n){
            cap = n;
            arr = new int[cap];
            top1 = -1;
            top2 = cap;
        }

        bool push1(int x){
            if(top1 < top2 - 1){
                top1++;
                arr[top1] = x;
                return true;
            }
            return false;
        }

        bool push2(int x){
            if(top1 < top2 - 1){
                top2--;
                arr[top2] =  x;
                return true;
            }
            return false;
        }

        int pop1(){
            int *temp = NULL;
            if(top1>=0){
                int res = arr[top1];
                top1--;
                return res;
            }
            return *temp;
        }

        int pop2(){
            int *temp = NULL;
            if(top2<cap){
                int res = arr[top2];
                top2++;
                return res;
            }
            return *temp;
        }

        int size1(){
            return top1 + 1;
        }

        int size2(){
            return cap - top2;
        }
        
        void Top(){
            cout<<arr[top1]<<" "<<arr[top2]<<endl;
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


    myStack2 st(10);

    st.push1(10);
    st.push1(20);
    st.push2(10);
    st.Top();


    return 0;
}
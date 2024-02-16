#include<bits/stdc++.h>
using namespace std;


class k_stack{
    private:
        int *arr , *top , *next;
        int cap , k , free_top;
    public:
        k_stack(int n , int k1){
            cap = n;
            k = k1;
            arr = new int[cap];
            top = new int[k];
            next = new int[cap];
            fill(top , top + k , -1);
            for(int i = 0 ; i<cap - 1 ; i++){
                next[i] = i+1;
            }
            next[cap-1] = -1;
            free_top = 0;
        }

        void push(int x , int sn){
            if(free_top == -1){
                cout<<"OverFlow"<<endl;
                return;
            }
            int i = free_top;
            free_top = next[i];
            next[i] = top[sn];
            top[sn] = i;
            arr[i] = x;
        }

        int pop(int sn){
            if(top[sn] == -1){
                cout<<"UnderFlow"<<endl;
                return -1;
            }
            int i = top[sn];
            top[sn] = next[i];
            next[i] = free_top;
            free_top = i;
            return arr[i];
        }
};


int main(){
    
    k_stack s(5 , 2);
    s.push(10 , 0);
    s.push(20 , 0);
    s.push(20 , 0);
    s.push(20 , 0);
    s.push(30 , 0);
    
    cout<<s.pop(0)<<endl;

    s.push(10 , 1);
    s.push(20 , 1);
    cout<<s.pop(1)<<endl;

    return 0;
}
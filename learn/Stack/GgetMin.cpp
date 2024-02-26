#include<bits/stdc++.h>
using namespace std;

// Naive solution //
class myStack{
    private:
        stack<int> ms;
        stack<int> as;
        
    public:
    void push(int x){
        if(ms.empty()){
            ms.push(x);
            as.push(x);
            return;
        }

        ms.push(x);
        if(ms.top()<=as.top()){ // less tha curr min
            as.push(x);
        }
    }

    void pop(){
        if(as.top()==ms.top()){ // if curr min is being poped out
            as.pop();
        }
        ms.pop();
    }

    int getMin(){
        return as.top();
    }
};

// Efficient Solution with out considering the negative values//
class myStackEff{
    private:
        stack<int> s;
        int min;
    public:
        void push(int x){
            if(s.empty()){
                min = x;
                s.push(x);
            }
            else if(x<=min){
                s.push(x-min);
                min = x;
            }
            else{
                s.push(x);
            }
        }
        int pop(){
            int t = s.top();
            s.pop();
            if(t<=0){
                int res = min;
                min = min - t;
                return res;
            }
            else{
                return t;
            }
        }

        int seek(){
            int t = s.top();
            return t<=0? min : t;
        }

        int getMin(){
            return min;
        }

        void dis(){
            while(s.empty()==false){
                cout<<s.top()<<" ";
                s.pop();
            }
        }

};


//Efficient solution considering the -ves als //
class mStack{
    private:
        stack<int> s;
        int min;
    public:
        void push(int x){
            if(s.empty()){
                s.push(x);
                min = x;
            }
            else if(x<=min){
                s.push(2*x - min);
                min = x;
            }else{
                s.push(x);
            }
        }

        int pop(){
            int t = s.top();
            s.pop();
            if(t<=min){
                int res = min;
                min = 2*min - t;
                return res;
            }
            else{
                return t;
            }
        }

        void seek(){
            int t = s.top();
            int r = t<=min?min : t;
            cout<<r<<endl;
        }
        int getMin(){
            return min;
        }


};

int main(){
    mStack ms;
    ms.push(5);
    ms.push(13);
    ms.push(2);
    ms.push(2);
    ms.push(5);
    ms.push(2);
  
    cout<<ms.getMin()<<endl;
   


    return 0;
}
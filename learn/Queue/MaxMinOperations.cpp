#include<bits/stdc++.h>
using namespace std;

class myDS{
    private:
        deque<int> dq;
    public:
        void inserMin(int x){
            dq.push_front(x);
        }
        void insertMax(int x){
            dq.push_back(x);
        }
        int getMin(){
            return dq.front();
        }
        int getMax(){
            return dq.back();
        }

        void extractMin(){
            dq.pop_front();
        }

        void extractMax(){
            dq.pop_back();
        }

};

int main(){
    
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;
// naive solution //
void divisors(int N){
    vector<int> v1;
    for (int i=1;i<=N;i++){
        if(N%i==0){
            v1.push_back(i);
        }
    }

    for(int j=0;j<v1.size();j++){
        cout<<v1[j]<<" ";
    }
}


int main(){
    

    divisors(20);


    
    return 0;
}
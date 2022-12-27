
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
    cout<<endl;
}


// Efficient solution //
void printdivo(int n){
    for(int i=1; i*i<=n;i++){
        if(n%i==0){
            cout<<i<<" ";
            if(i!=n/i){
                cout<<n/i<<" ";
            }
        }
        
    }
    cout<<endl;
}

// more efficient //

void pindivo(int n){
    int k;
    for(k=1;k*k<=n;k++){
        if(n%k==0){
            cout<<k<<" ";
        }
    }
    k=k-1;
    for(;k>=1;k--){
        if(n%k==0){
            cout<<n/k<<" ";
        }
    }
    cout<<endl;

}


int main(){
    

    divisors(20);
    printdivo(20);
    pindivo(15);


    
    return 0;
}
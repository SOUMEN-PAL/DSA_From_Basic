#include <iostream>
using namespace std;

long long div(int n){
    long long count=0;
    for(int i=1;i<=n;i++){
        int div=0;
        for(int j=1; j*j<=i;j++){
            if(n%j==0){
                div=div+1;
                if(i!=n/j){
                    div=div+1;
                }
            }
        
        }
        if(div==3){
            count+=1;
        }
    }

    return count;
    
    
}

bool isPrime(int n){

        for(int i=2;i*i<=n;i++){

            if(n%i==0) return false;

        }

        return true;

    }

 

void exactly3Divisors(int N)

    {

        int cnt = 0;

        for(int i=2;i*i<=N;i++){

            if(isPrime(i)){

                cout<<i*i<<" ";

            }

        }

        // return cnt;

    }



int main(){
    
    cout<<div(13)<<endl;
    exactly3Divisors(64);


    
    return 0;
}










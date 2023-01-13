#include <iostream>
using namespace std;

// naive solution //
void setbit(int n , int k){
    if(n==0){
        cout<<"Not Set"<<endl;
    }
    else{
        for(int i=0 ; i<(k-1) ; i++){
            n=n/2;
        }
        if((n&1)!=0){
            cout<<"Set"<<endl;
        }
        else{
            cout<<"Not Set"<<endl;
        }
        
    }

}
void setbit_2(int n , int k){
    if(n=0){
        cout<<"Yes"<<endl;
    }
    else{
        int x=1;
        for(int i=0 ; i<(k-1);i++){
            x=x*2; // aka 2^(k-1) //

        }
        if((n&x)!=0){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }        
    }

    
}

int main(){
    int n ,k;
    cout<<"Enter the values: ";
    cin>>n>>k;
    setbit(n,k);
    setbit_2(n,k);
    


    return 0;
}
#include <iostream>

using namespace std;

void primefactor(int n){
    for(int i =2; i*i<=n ;i++){
        while(n%i==0){
            cout<<i<<" ";
            n=n/i;
        }
    }
    if(n>1){
        cout<<n<<" ";
    }
// time complexity of O(rootn log n) //  

    cout<<endl;
}


void primo(int n){
    for(int i=2;i<=n;i++){
        while(n%i==0){
            cout<<i<<" ";
            n=n/i;

        }
    }
// time complexity of O(n log n)
    cout<<endl;
}


void fuck(int n){
    for(int i=2; i*i<=n ;i++){
        while(n%i==0){
            cout<<i<<" ";
            n=n/i;
        }


    }
    if(n>1){
        cout<<n<<" ";
    }
}




int main(){
    

    int x;
    cout<<"enter the no: ";
    cin>>x;
    primefactor(x);
    primo(x);
    fuck(x);



    
    return 0;
}
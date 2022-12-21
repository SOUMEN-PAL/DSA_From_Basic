#include <iostream>
using namespace std;

int GCD(int a,int b){
    if (b==0){
        return a;
    }
    else{
        return GCD(b,a%b);
    }
}

int lcm(int a,int b){
    return a*b/GCD(a,b);
}


int LCM(int n, int m){
    int res=max(n,m);
    while(true){
        if(res%n==0 && res%m==0){
            return res;
        }
        res++;
    }
    return res;

}


int main(){
    
    int a,b;
    cin>>a>>b;
    cout<<lcm(a,b)<<endl;
    cout<<LCM(a,b)<<endl;
    




    return 0;
}
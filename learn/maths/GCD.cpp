#include <iostream>
#include <math.h>
using namespace std;



int GCD(int a,int b){
    int ans=1;
    int res = min(a,b);
    // int x=a;
    // int y=b;
    for(int i=res;i>0;i--){

        if(a%i==0 and b%i==0){
            ans=i;
            break;
        }


    }
    return ans;
}


int main(){
    int n1;
    int n2;
    cout<<"Enter both the numbers: ";
    cin>>n1>>n2;
    cout<<"THe GCD is: "<<GCD(n1,n2);





    
    return 0;
}
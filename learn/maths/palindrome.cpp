#include <iostream>
using namespace std;

string palin(int x){
    int rev=0;
    int temp=x;
    while(temp!=0){
        
        rev=rev*10+temp%10;
        temp=temp/10;
    }
    cout<<"The reverse is: "<<rev<<endl;

    if (rev==x){
        return "It's a palindrone";
    }
    else{
        return "It's not a palindrone";
    }
    
}


int main(){
    int x;
    cout<<"Enter a no: ";
    cin>>x;
    cout<<palin(x);
    



    
    return 0;
}
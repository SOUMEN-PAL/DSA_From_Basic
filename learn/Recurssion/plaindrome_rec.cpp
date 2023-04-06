#include <bits/stdc++.h>
using namespace std;

bool palindrome(string &a , int start , int end){

    if(start>=end){
        return true;
    }

    // here its not changing the string only the start and end will be changed // 
    return (a[start]==a[end]) && palindrome( a , start+1 , end-1);



}




int main(){
    string str;
    cout<<"Enter the string: ";
    cin>>str;
    bool x = palindrome(str , 0 , str.size()-1);
    if(x==true){
        cout<<"Plaindrome"<<endl;
    }
    else{
        cout<<"Not a plaindrome"<<endl;
    }


    return 0;
}
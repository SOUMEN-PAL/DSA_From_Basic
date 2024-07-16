#include<bits/stdc++.h>
using namespace std;

string smallestNumber(int s, int d) {
        // code here
        if(s == 0){
            if(d == 1){
                return "0";
            }
            else{
                return "-1";
            }
        }
        if(s > 9*d){
            return "-1";
        }
        string res = "";
        s = s - 1;
        for(int i = d-1; i > 0; i--){
            if(s > 9){
                res = "9" + res;
                s = s - 9;
            }
            else{
                res = to_string(s) + res;
                s = 0;
            }
        }
        res = to_string(s+1) + res;
        return res;
    }


int main(){

    cout<<smallestNumber(9,2)<<endl;
    
    return 0;
}
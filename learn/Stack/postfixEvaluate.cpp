#include<bits/stdc++.h>
using namespace std;

// POst fix to infix //
int evalPostFix(string s){
    stack<int> st;
    int n = s.length();
    for(int i = 0 ; i<n ; i++){
        char x = s[i];
        if(x == ' '){
            continue;
        }

        else if(isdigit(x) == true){
            int res = 0;
            while(isdigit(s[i])){
                res = (res*10) + (s[i]-'0');
                i++;
            }
            i--;
            st.push(res);
        }
        else{
            int op1 = st.top();st.pop();
            int op2 = st.top();st.pop();
            int res;
            switch (x)
            {
            case '+':
                res = op1 + op2;
                break;
            case '-':
                res = op2 - op1;
                break;
            case '/':
                res = op2 / op1;
                break;
            case '*':
                res = op2*op1;
                break;
            case '^':
                res = pow(op2 , op1);
                break;
            default:
                break;
            }
            st.push(res);
        }
    }


    return st.top();
}

int main(){
    string s = "100 200 + 2 / 5 * 7 +";
    cout<<evalPostFix(s);
    return 0;
}
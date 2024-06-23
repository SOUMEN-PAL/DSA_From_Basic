#include<bits/stdc++.h>
using namespace std;

int prec(char ch){
    if(ch == '^'){
        return 3;
    }
    else if(ch == '/' || ch == '*'){
        return 2;
    }
    else if(ch == '+' || ch == '-'){
        return 1;
    }
    else{
        return -1;
    }
}

string infixToPostFix(string s){
    int n = s.length();
    stack<char> st;
    string res = "";
    for(int i = 0 ; i<n ; i++){
        int x = s[i];
        if((x>='a' && x<='z') || (x>='A' && x<='Z') || (x>='0' && x<='9')){
            res.push_back(x);//string me
        }
        else if(x == '('){
            st.push(x);//stack me
        }
        else if(x == ')'){
            while(st.top() != '('){
                res.push_back(st.top());
                st.pop();
            }
            st.pop(); // we do not need that ( for the future checks //
        }
        else{
            while(!st.empty() && prec(x)<=prec(st.top())){
                // abhi toh left to right ho ha equals me par agar kuch alag hua toh uske liye ek pura prec table chaiye //
                res.push_back(st.top());
                st.pop();
            }
            st.push(x);
        }
    }
    while(st.empty()==false){
        res.push_back(st.top());
        st.pop();
    }
    return res;
}


int main(){
    
    string str = "a+b*c";
    cout<<infixToPostFix(str)<<endl;


    return 0;
}
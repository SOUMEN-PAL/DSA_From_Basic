#include<bits/stdc++.h>
using namespace std;


//___________Naive SOlution_______________//
int Square_root(int n){
    int i;
    for(i = 0 ; i<n ; i++){
        if(i*i<n){
            continue;
        }
        else{
            break;
        }
    }
    return i;
}



//_____________Efficient Slution_________________//

int square_root(int n){
    int low = 1 , high = n , res = -1;
    while(high>=low){
        int mid = (high + low)/2;
        int sqM = mid * mid;
        if(sqM == n){
            return mid;
        }
        else if(sqM > n){
            high = mid -1;
        }
        else{
            low = mid+1;
            res = mid;
        }
    }
    return res;
}

int main(){
    int n;
    cout<<"ENter n: ";
    cin>>n;

    cout<<square_root(n)<<endl;
    cout<<Square_root(n)<<endl;
    return 0;
}
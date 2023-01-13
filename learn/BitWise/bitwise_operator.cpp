#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int x=3;
    int y=6;
    unsigned z=1;
    cout<<"Following are all bitwise operations: ";
    cout<<(x&y)<<" "<<(x|y)<<" "<<(x^y)<<" "<<(x<<1)<<" "<<(y>>2)<<" "<<(~z);
    


    return 0;
}
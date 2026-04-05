#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

int ToH(int n , char A , char B , char C){
    static int x = n;
    if(n==1){
        cout<<"Move "<<n<<" from "<<A<<" to "<<C<<endl;
        return pow(2,x)-1;
    }

    ToH(n-1 , A , C , B);
    cout<<"Move "<<n<<" from "<<A<<" to "<<C<<endl;
    ToH(n-1 , B , A , C);
}


// another solution //
long long toh(int N, int from, int to, int aux) {
     // Your code here
    if(N>0)
    {    
        toh(N-1,from,aux,to);
        cout<<"move disk "<<N<<" from rod "<<from<<" to rod "<<to<<"\n";
        toh(N-1,aux,to,from);
    } 
    return pow(2,N)-1; // this part is not in else so it will be running after the recc call  all the times //
}


int main(){
    cout<<ToH(4 , 'A' , 'B' , 'C')<<endl;
    // cout<<toh(3 , 1 , 3 , 2)<<endl;

    return 0;
}
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

int fib(int n){
    int f[n+1];
    f[0] = 0;
    f[1] = 1;

    for(int i = 2 ; i<=n ; i++){
        f[i] = f[i-1] + f[i-2];
    }


    return f[n];
}



int main()
{

    int a;
    cout<<"Enter a number: ";

    cin>>a;

    cout<<"The no is: "<<fib(a-1)<<endl;

    
    return 0;
}
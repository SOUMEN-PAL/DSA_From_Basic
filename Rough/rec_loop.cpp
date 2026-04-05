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
void permute(string str, int i,int j)
{
	if (i == j-1)
		{
		    cout<<str<<endl;
		    return;
		}
	else
	{
		for (int k= i; k <= j-1; k++)
		{
            cout<<"FIrst k: "<<k<<" First i: "<<i<<endl;
			swap(str[i], str[k]);        

            permute(str, i + 1, j);

            cout<<"Second k: "<<k<<" Second i: "<<i<<endl;
            swap(str[i], str[k]);
	    }
	}
}

int main(){
    permute("AB" ,  0   , 2);
    return 0;
}
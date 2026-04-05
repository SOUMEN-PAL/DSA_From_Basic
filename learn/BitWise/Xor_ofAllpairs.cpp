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


long long int sumXOR(int arr[], int n)
{
	long long int countOnes , countZeroes;
	long long int res = 0;
	int temp = 1;
	int m = INT_MIN;
	//finding maz int the array //
	for(int i = 0 ; i<n ; i++){
	    m = max(m , arr[i]);
	}
	
	int msb = floor(log2(m)) + 1; // msb of the maximum number so to misnimise the k even more;
	
	for(int i = 0 ; i<msb ; i++){
	    countOnes = 0;
	    countZeroes = 0;
	    for(int j = 0 ; j<n ; j++){
	        if(((temp<<i) & arr[j]) != 0){ // Dont use == 1 in the check its decimal check buddy//
	            countOnes++;
	        }
	        else{
	            countZeroes++;
	        }
	    }
	    
	    res += (countOnes * countZeroes * (1<<i));
	}
	return res;
}

int main(){
    
    return 0;
}
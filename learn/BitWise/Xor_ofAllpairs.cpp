#include<bits/stdc++.h>
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

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// naive solution //
void divisors(int N){
    vector<int> v1;
    for (int i=1;i<=N;i++){
        if(N%i==0){
            v1.push_back(i);
        }
    }

    for(int j=0;j<v1.size();j++){
        cout<<v1[j]<<" ";
    }
    cout<<endl;
}


// Efficient solution //
void printdivo(int n){
    vector<int> v2;
    for(int i=1; i*i<=n;i++){
        if(n%i==0){
            v2.push_back(i);
            if(i!=n/i){
                v2.push_back(n/i);
            }
        }
        
    }
    sort(v2.begin(),v2.end());
    cout<<"The sorted and efficient method is: ";
    for(int i=0;i<v2.size();i++){
         cout<<v2[i]<<" ";
    }
    cout<<endl;
}

// more efficient(sorted) //

void pindivo(int n){
	int i = 1;
	for(i=1; i*i <n; i++)
	{
        // cout<<"i:"<<i<<" ";
		if(n % i == 0)
		{
			cout<<i<<" ";
		}
	}
    
	for(; i >= 1; i--)
	{
        // cout<<"ri:"<<i<<" ";
		if(n % i == 0)
		{
			cout<<(n / i)<<" ";
		}
	}
    cout<<endl;
}


int main(){
    

    divisors(20);
    printdivo(20);
    pindivo(25);
    pindivo(12);


    
    return 0;
}
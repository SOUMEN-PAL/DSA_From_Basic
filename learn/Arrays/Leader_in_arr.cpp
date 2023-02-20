#include <bits/stdc++.h>
using namespace std;


// naiv solution //
void lead(int arr[] , int n){
	for(int i = 0; i < n; i++)
	{
		bool flag = false;

		for(int j = i + 1; j < n; j++)
		{
			if(arr[i] <= arr[j])
			{
				flag = true;
				break;
			}
		}

		if(flag == false)
		{
			cout<<arr[i]<<" ";
		}
	}
	cout<<endl;


}

// efficient solution //

void leader(int arr[] , int n){
	int curr_lead = arr[n-1];
	// we know that the last element is always a leader //
	cout<<curr_lead<<" ";
	for(int i = n-2 ; i>=0 ; i--){
		if(arr[i]>curr_lead){
			curr_lead = arr[i]; // updating the value of current lead //
			cout<<curr_lead<<" ";

		}
	}
	cout<<endl;
// TC : O(n)
// AS : O(1)
}




int main(){
    int arr[] = {7,10,4,3,6,5,2};
    int n = sizeof(arr)/sizeof(arr[0]);

    lead(arr, n);
	leader(arr , n);
    
    return 0;
}
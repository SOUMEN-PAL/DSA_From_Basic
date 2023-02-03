#include <bits/stdc++.h>
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
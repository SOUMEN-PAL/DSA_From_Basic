#include <bits/stdc++.h>
using namespace std;

/*
 --------- My approach was wrong what i did is update the value of I for every itreation but i had to update it if it has the same value else not---------
void fre(int arr[] , int n){
    int count = 1;
    for(int i = 1 ; i<n ; i++){
        for( i ; i<n ; i++){
            if(arr[i-1]==arr[i]){
                count++;

            }
        }
        cout<<count<<endl;
        count = 1;
    }
    
}
*/
// as the array is sorted or the similar element s are consecutive so it is easy to check for the repeated elements count //

// for loop solutuiion //
void fre(int arr[] , int n){
    int count = 1;
    for(int i  = 1 ; i<n ; i++){
        if(arr[i-1] == arr[i]){
            count++;
        }
        else{
            cout<<"The frequency of "<<arr[i-1]<<" is: "<<count<<endl;
            count = 1;
        }
    }
    cout<<"The frequency of "<<arr[n-1]<<" is: "<<count<<endl; // (I)
    count = 1; // this part is for the last repeated elements //

}

// while loop approach //

void wh_fre(int arr[] , int n){
    int i = 1;
    int c = 1;
    while(i<n){
        if(arr[i-1]==arr[i]){
            c++;

        }
        else{
            cout<<"The frequency of "<<arr[i-1]<<" is: "<<c<<endl;
            c = 1;            
        }
        i++; // as i ko update hona ha har time jab arr[i-1] == arr[i] ha and tab bhi jab arr[i-1] != arr[i] taki age waleh values bhi check ho sake //
            // ans infinite loop bhi chalu na ho //

    }
    cout<<"The frequency of "<<arr[i-1]<<" is: "<<c<<endl;  // (II)
    c = 1;  
    
}


// both (I) and (II) are runed because as the last elements would not have any element after them to be checked with //
// Time Complexity : O(n)//
// Auxilary Space : O(1)//

// GFG told approach //

void frequency(int arr[] , int n){
    int i = 1 , c = 1;
    while(i<n){
        while(i<n && arr[i-1]==arr[i]){
            c++;
            i++;
        }
        cout<<"The frequency of "<<arr[i-1]<<" is: "<<c<<endl;
        i++;
        c = 1;
    }

    if(n==1 || arr[n-1]!=arr[n-2]){
        cout<<"The frequency of "<<arr[n-1]<<" is: "<<1<<endl;

    }
}


int main(){
    int arr[] = {1, 1, 1, 2, 3, 3, 5, 5, 8, 8, 8, 9, 9, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"------For lopp Approach"<<endl;   
    fre(arr , n);
    cout<<"------While lopp Approach"<<endl;
    wh_fre(arr , n);
    cout<<"------GFG approach"<<endl;
    frequency(arr , n);

    return 0;
}
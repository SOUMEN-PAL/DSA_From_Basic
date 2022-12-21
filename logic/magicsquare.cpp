#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    
    int n;
    cout<<"Enter the value: ";
    cin>>n;
    int size=(2*n)-1;
    int start=0;
    int end=size-1;

    // cout<<size;
    int array[size][size];
    int temp=n;

    while(temp!=0){
        for(int i=start;i<=end;i++){
            for(int j=start;j<=end;j++){
                if(i==start || i==end || j==start || j==end){
                    array[i][j]=temp;
                }

            }
           
        }
        start++;
        end--;
        temp--;
    }
    start=0;
    end=size-1;
    temp=n;

    
    for(int i=start;i<=end;i++){
        for(int j=start;j<=end;j++){
            cout<<setw(2)<<array[i][j]<<" ";
        }
        cout<<endl;
    }
    start++;
    end--;
        

    



    cin.get();
    return 0;
}
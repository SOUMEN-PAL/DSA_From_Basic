#include <iostream>
#include <vector>

using namespace std;

void seive(int a){
    vector<bool> v(a+1,true);
    for(int i=2;i*i<=a;i++){
        if(v[i]==true){
            for(int j=2*i;j<=a; j=j+i){
                v[j]=false;
            }
        }
    }
    for(int i=2;i<=a;i++){
        if(v[i]==true){
            cout<<i<<" ";
        }
    }
    cout<<endl;
}
void effsteve(int a){
   vector<bool> vec(a+1,true);
   for(int i=2;i*i<=a;i++){
       if(vec[i]==true){
           for(int j=i*i;j<=a; j=j+i){
               vec[j]=false;
           }
       }
   }
   for(int i=2;i<=a;i++){
       if(vec[i]==true){
           cout<<i<<" ";
       }
   }
   cout<<endl;
}

void mrstevee(int n){
    vector <bool> v2(n+1,true);
    for(int i=2 ; i<=n ; i++){
        if(v2[i]==true){
            cout<<i<<" ";
            for(int j=i*i ; j<=n ; j=j+i){// tc O(nloglogn) //
                v2[j]=false;
            }
        }
    }
}

int main(){
    
    seive(10);
    effsteve(10);
    mrstevee(10);
    
    
    return 0;
}
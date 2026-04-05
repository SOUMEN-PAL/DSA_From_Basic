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

vector<double> medianStream(vector<int> arr){
    priority_queue<int> lt;
    priority_queue<int , vector<int> , greater<>> rt;
    vector<double> res;
    int n = arr.size();
    lt.push(arr[0]);
    res.push_back(arr[0]);
    for(int i = 1 ; i<n ; i++){
        int x = arr[i];
        if(lt.size() > rt.size()){
            if(lt.top() > x){
                rt.push(lt.top());
                lt.pop();
                lt.push(x);
            }
            else{
                rt.push(x);
            }

            res.push_back((double)(lt.top() + rt.top())/2); // as these were uneven now after addig obe element its even in size so even logic
        }else{
            if(lt.top() >= x){
                lt.push(x);
            }
            else{
                rt.push(x);
                lt.push(rt.top());
                rt.pop();
            }
            res.push_back(lt.top());
        }
    }
    return res;
}

int main(){
    vector<int> arr = {5, 15, 10, 20, 3};
    vector<double> res = medianStream(arr);
    for(auto x : res){
        cout<<x<<" ";
    }
    
    return 0;
}
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

class myDS{
    private:
        deque<int> dq;
    public:
        void inserMin(int x){
            dq.push_front(x);
        }
        void insertMax(int x){
            dq.push_back(x);
        }
        int getMin(){
            return dq.front();
        }
        int getMax(){
            return dq.back();
        }

        void extractMin(){
            dq.pop_front();
        }

        void extractMax(){
            dq.pop_back();
        }

};

int main(){
    
    return 0;
}
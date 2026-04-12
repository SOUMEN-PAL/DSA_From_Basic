#include <bits/stdc++.h>
using namespace std;

using ll = long long;

pair<int , int> getIndices(
    vector<int> nums
){
    int currSum = nums[0], maxSum = nums[0];
        int tempStart = 0, start = 0, end = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > currSum + nums[i]) {
                currSum = nums[i];
                tempStart = i;
            } else {
                currSum += nums[i];
            }

            if (currSum > maxSum) {
                maxSum = currSum;
                start = tempStart;
                end = i;
            }
        }

        return {start, end};
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    return 0;
}
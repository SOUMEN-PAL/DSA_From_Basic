#include <bits/stdc++.h>
using namespace std;

    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        for(int i = 0 ; i< 1<<n ; i++){
            if(i<n){
                string binary = bitset<16>(i).to_string().substr(16-n);
                if(binary != nums[i]){
                    return binary;
                }
            }
            else{
                return bitset<16>(i).to_string().substr(16-n);
            }
        }
        return "";
    }
int main() {
    std::vector<std::string> nums1 = {"00", "01", "10"};
    assert(findDifferentBinaryString(nums1) == "11");

    std::vector<std::string> nums2 = {"01", "10"};
    assert(findDifferentBinaryString(nums2) == "00");

    std::vector<std::string> nums3 = {"000", "001", "010", "011", "100", "101", "110", "111"};
    assert(findDifferentBinaryString(nums3) == "");

    std::vector<std::string> nums4 = {"0", "1"};
    assert(findDifferentBinaryString(nums4) == "00");

    std::vector<std::string> nums5 = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};
    assert(findDifferentBinaryString(nums5) == "");

    return 0;
}



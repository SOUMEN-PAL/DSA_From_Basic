
#include <unordered_set>
#include <algorithm>

int lengthOfLongestSubstring(std::string s) {
    int maxLength = 0;
    std::unordered_set<char> seen;

    for (int start = 0, end = 0; end < s.length(); end++) {
        while (seen.find(s[end]) != seen.end()) {
            seen.erase(s[start]);
            start++;
        }
        seen.insert(s[end]);
        maxLength = std::max(maxLength, end - start + 1);
    }

    return maxLength;
}

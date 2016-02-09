class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int last[256];
        memset(last, -1, sizeof last);
        int result = 0;
        int max = -1;
        for (int i = 0; i < s.size(); i++) {
            max = std::max(max, last[s[i]]);
            last[s[i]] = i;
            result = std::max(result, i - max);
        }
        return result;
    }
};

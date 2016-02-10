class Solution {
public:
    string longestPalindrome(string s) {
        memset(dp, 0, sizeof dp);
        result = {0, 0};
        int n = s.size();
        for (int length = 0; length < n; length++)
            for (int i = 0; i < n - length; i++){
                if (length == 0) {dp[i][i] = true;maintain({length + 1, i});}
                else if (length == 1) {
                    if (s[i] == s[i + length]) {
                        dp[i][i + length] = true;
                        maintain({length + 1, i});
                    }
                } else {
                    if (s[i] == s[i + length]) {
                        if (dp[i + 1][i + length - 1]) {
                            dp[i][i + length] = true;
                            maintain({length + 1, i});
                        }
                    }
                }
            }
        return s.substr(result.second, result.first);
    }
    void maintain(pair<int, int> x) {
        result = max<pair<int, int> >(result, x);
    }
private:
    bool dp[1000][1000];
    pair<int, int> result;
};

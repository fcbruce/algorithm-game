bool isMatch(char* s, char* p) {
    int ls = strlen(s);
    int lp = strlen(p);
    bool dp[ls + 1][lp + 1];
    memset(dp, false, sizeof dp);
    
    dp[0][0] = true;
    
    for (int i = 1;i < lp; i++) {
        if (p[i] == '*') {
            dp[0][i + 1] = dp[0][i - 1];
        }
    }
    
    for (int i = 0; i < ls; i++) {
        for (int j = 0; j < lp; j++) {
            if (s[i] == p[j] || p[j] == '.') dp[i + 1][j + 1] = dp[i][j];
            
            if (p[j] == '*') {
                if (dp[i + 1][j - 1] || dp[i + 1][j]) dp[i + 1][j + 1] = true;
                else if (s[i] == p[j - 1] || p[j - 1] == '.') dp[i + 1][j + 1] = dp[i][j + 1];
            }
            
        }
    }
    
    return dp[ls][lp];

}

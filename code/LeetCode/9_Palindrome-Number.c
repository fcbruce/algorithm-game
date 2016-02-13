bool isPalindrome(int x) {
    if (x < 0) return false;
    if (x == 0) return true;
    int s[16];
    int n = 0;
    while (x) {
        s[n++] = x % 10;
        x /= 10;
    }
    for (int i = 0, j = n - 1; i < j; i++, j--)
        if (s[i] != s[j]) return false;
    return true;
}

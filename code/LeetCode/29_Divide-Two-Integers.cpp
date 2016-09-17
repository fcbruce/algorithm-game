class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) return INT_MAX;
        if (divisor == -1 && dividend == INT_MIN) return INT_MAX;
        
        long long x = dividend, y = divisor;
        int sign = (x < 0) ^ (y < 0);
        if (x < 0) x = -x;
        if (y < 0) y = -y;
        
        long long res = 0;
        
        while (x >= y)
        {
            long long z = y;
            long long tmp = 1;
            while (x >= (z << 1))
            {
                z <<= 1;
                tmp <<= 1;
            }
            x -= z;
            res |= tmp;
        }
        
        return sign ? -res : res;
        
    }
};

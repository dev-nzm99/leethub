class Solution {
public:
    int mySqrt(int x) {
        long long l = 1, r = x;
        int res = 0;
        while (l <= r) {
            long long m = l + (r - l) / 2;
            if (m * m == x)
                return m;
            else if (m * m > x) {
                res = m - 1;
                r = m - 1;
            } else
                l = m + 1;
        }
        return res;
    }
};
class Solution {
public:
    int mySqrt(int x) {
        long l = 0, r = x;
        long mid = 0;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (mid * mid <= x && (mid + 1) * (mid + 1) > x)
                return mid;
            else if (x < mid * mid)
                r = mid - 1;
            else // x >= (mid + 1) * (mid + 1)
                l = mid + 1;
        }
        return l;
        
    }
};
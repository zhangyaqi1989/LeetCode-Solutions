// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int lo = 1, hi = n;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (mid == 1) return isBadVersion(mid) ? 1 : hi;
            if (!isBadVersion(mid - 1) && isBadVersion(mid)) {
                return mid;
            } else if (isBadVersion(mid - 1)) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};

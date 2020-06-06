/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
class Solution {
public:
    int findInMountainArray(int target, MountainArray &A) {
        int n = A.length();
        int lo = 0, hi = n - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (A.get(mid) < A.get(mid + 1)) lo = mid + 1;
            else hi = mid;
        }
        int l = 0, r = lo;
        while (l < r) {
            int m = l + (r - l) / 2;
            int val = A.get(m);
            if (val == target) return m;
            else if (val < target) l = m + 1;
            else r = m - 1;
        }
        if (A.get(l) == target) return l;
        l = lo + 1, r = n - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            int val = A.get(m);
            if (val == target) return m;
            else if (val < target) r = m - 1;
            else l = m + 1;
        }
        if (A.get(l) == target) return l;
        return -1;
    }
};

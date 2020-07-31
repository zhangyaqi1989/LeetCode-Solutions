/**
 * // This is ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface ArrayReader {
 *     // Compares the sum of arr[l..r] with the sum of arr[x..y] 
 *     // return 1 if sum(arr[l..r]) > sum(arr[x..y])
 *     // return 0 if sum(arr[l..r]) == sum(arr[x..y])
 *     // return -1 if sum(arr[l..r]) < sum(arr[x..y])
 *     public int compareSub(int l, int r, int x, int y) {}
 *
 *     // Returns the length of the array
 *     public int length() {}
 * }
 */

class Solution {
    public int getIndex(ArrayReader reader) {
        int n = reader.length();
        int lo = 0, hi = n - 1;
        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int cnt = hi - lo + 1;
            if(cnt % 2 == 1) {
                int l = lo, r = mid - 1;
                int x = mid + 1, y = hi;
                int com = reader.compareSub(l, r, x, y);
                if(com == 1) {
                    lo = l;
                    hi = r;
                } else if (com == 0) {
                    return mid;
                } else {
                    lo = x;
                    hi = y;
                }
            } else {
                int l = lo, r = mid;
                int x = mid + 1, y = hi;
                int com = reader.compareSub(l, r, x, y);
                if(com == 1) {
                    lo = l;
                    hi = r;
                } else {
                    lo = x;
                    hi = y;
                }
            }
        }
        return lo;
    }
}

class Solution {
    public int hIndex(int[] citations) {
        int n = citations.length;
        if (n == 0) return 0;
        if (citations[n - 1] < 1) return 0;
        int lo = 0, hi = n - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (n - mid <= citations[mid]) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return n - lo;
    }
}

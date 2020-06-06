class Solution {
    public int hIndex(int[] citations) {
        Arrays.sort(citations);
        int n = citations.length;
        int lo = 0, hi = n;
        while (lo < hi) {
            int mid = (lo + hi) >> 1;
            if (citations[mid] < n - mid) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return n - lo;
    }
}

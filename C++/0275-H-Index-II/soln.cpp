class Solution {
public:
    int hIndex(vector<int>& citations) {
        // if h papers has at least h citations
        if (citations.empty()) return 0;
        int n = citations.size();
        // if (citations[0] >= n) return n;
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
};

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int lo = 0, hi = n;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (citations[mid] < n - mid) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return n - lo;
    }
};

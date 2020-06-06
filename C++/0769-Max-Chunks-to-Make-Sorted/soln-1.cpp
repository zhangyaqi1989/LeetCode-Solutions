class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        // 0 ... n - 1
        int cnt = 0;
        const int n = arr.size();
        int r = -1;
        for(int i = 0; i < n; ++i) {
            r = max(r, arr[i]);
            if (r == i) ++cnt;
        }
        return cnt;
    }
};

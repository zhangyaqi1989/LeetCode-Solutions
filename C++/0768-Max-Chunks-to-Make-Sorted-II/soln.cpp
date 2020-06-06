class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        left[0] = arr[0];
        for(int i = 1; i < n; ++i) left[i] = max(arr[i], left[i - 1]);
        right[n - 1] = arr[n - 1];
        for(int j = n - 2; j >= 0; --j) right[j] = min(arr[j], right[j + 1]);
        int res = 1;
        for(int i = 0; i < n - 1; ++i) {
            if (left[i] <= right[i + 1]) ++res;
        }
        return res;
    }
};

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> dup(arr);
        int idx = 0, n = arr.size();
        for(int i = 0; i < n && idx < n; ++i) {
            arr[idx++] = dup[i];
            if (idx >= n) break;
            if (dup[i] == 0) arr[idx++] = 0;
        }
    }
};

class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int best_diff = INT_MAX, best_val = 0;
        sort(arr.begin(), arr.end());
        int idx = 0;
        const int kN = arr.size();
        int hi = arr.back();
        int left = 0;
        for(int val = 0; val <= hi; ++val) {
            while(idx < kN && arr[idx] <= val) left += arr[idx++];
            int diff = abs(left + (kN - idx) * val - target);
            if (diff < best_diff) {
                best_diff = diff;
                best_val = val;
            }
        }
        return best_val;
    }
};

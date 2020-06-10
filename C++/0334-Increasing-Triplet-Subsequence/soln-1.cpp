class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // greedy
        // want to make arr[j] as big as possible
        // mx_right, max_cand
        int mx_right = INT_MIN, mx_mid = INT_MIN;
        const int n = nums.size();
        for(int i = n - 1; i >= 0; --i) {
            if (mx_mid > nums[i]) return true;
            if (nums[i] < mx_right && nums[i] > mx_mid) mx_mid = nums[i];
            mx_right = max(mx_right, nums[i]);
        }
        return false;
    }
};

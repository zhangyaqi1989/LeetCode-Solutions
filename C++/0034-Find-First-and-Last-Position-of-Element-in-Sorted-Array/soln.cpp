class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return {-1, -1};
        int lo = 0, hi = nums.size() - 1;
        int left;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        left = nums[lo] == target ? lo : -1;
        if (left == -1) return {-1, -1};
        lo = left;
        hi = nums.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] <= target) {
                if (lo == mid) return {left, nums[lo + 1] > target ? lo : lo + 1};
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        return {left, lo};
    }
};

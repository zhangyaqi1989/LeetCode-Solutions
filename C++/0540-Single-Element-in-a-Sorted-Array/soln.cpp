class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int lo = 0, hi = n - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if ((nums[mid] < nums[mid + 1] && (n - 1 - mid) % 2 == 1) || (nums[mid] == nums[mid + 1] && (n - 1 - mid) % 2 == 0)) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return nums[lo];
    }
};

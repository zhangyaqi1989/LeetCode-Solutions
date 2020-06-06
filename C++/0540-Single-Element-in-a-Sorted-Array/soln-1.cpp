class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        const int n = nums.size();
        int lo = 0, hi = n - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == nums[mid + 1]) {
                if (mid % 2 == 1) hi = mid - 1;
                else lo = mid + 2;
            } else {
                if ((hi - mid) % 2 == 1) lo = mid + 1;
                else hi = mid;
            }
        }
        return nums[lo];
    }
};

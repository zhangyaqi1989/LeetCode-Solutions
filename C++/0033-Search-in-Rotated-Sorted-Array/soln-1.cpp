class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        const int n = nums.size();
        int lo = 0, hi = n - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) return mid;
            else {
                if (nums[mid] > nums[hi]) { // left is sorted // mid == lo possible
                    if (nums[lo] <= target && target < nums[mid]) {
                        hi = mid - 1;
                    } else {
                        lo = mid + 1;
                    }
                } else {
                    if (nums[mid] < target && target <= nums[hi]) {
                        lo = mid + 1; 
                    } else {
                        hi = mid - 1;
                    }
                }
            }
        }
        return nums[lo] == target ? lo : -1;
    }
};

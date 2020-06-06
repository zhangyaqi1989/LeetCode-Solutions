class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sorted_nums(nums);
        sort(sorted_nums.begin(), sorted_nums.end());
        int n = nums.size();
        int lo = 0, hi = -1;
        for(int i = 0; i < n; ++i) {
            if (nums[i] != sorted_nums[i]) {
                lo = i;
                break;
            }
        }
        for(int i = n - 1; i >= lo; --i) {
            if (nums[i] != sorted_nums[i]) {
                hi = i;
                break;
            }
        }
        return hi - lo + 1;
    }
};

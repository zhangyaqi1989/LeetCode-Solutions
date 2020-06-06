class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        // map num to idx
        int miss = 0, dup = 0, n = nums.size();
        for(int i = 0; i < n; ++i) {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] < 0) dup = idx + 1;
            else nums[idx] = -nums[idx];
        }
        for(int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                miss = i + 1;
                break;
            }
        }
        return {dup, miss};
    }
};

class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        return min(countMoves(nums, true), countMoves(nums, false));
    }
    
    int countMoves(vector<int> nums, bool flag) {
        int n = nums.size();
        int cnt = 0;
        for(int i = 1; i < n; ++i) {
            if (flag) { // nums[i - 1] < nums[i]
                if (nums[i - 1] >= nums[i]) {
                    cnt += nums[i - 1] - nums[i] + 1;
                    nums[i - 1] = nums[i] - 1;
                }
            } else { // nums[i - 1] > nums[i]
                if (nums[i - 1] <= nums[i]) {
                    cnt += nums[i] - nums[i - 1] + 1;
                    nums[i] = nums[i - 1] - 1;
                } 
            }
            flag = !flag;
        }
        return cnt;
    }
};

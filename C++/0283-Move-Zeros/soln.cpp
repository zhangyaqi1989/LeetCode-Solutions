class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, n = nums.size();
        for(int num : nums) {
            if (num != 0) nums[i++] = num;
        }
        while (i < n) nums[i++] = 0;
    }
};

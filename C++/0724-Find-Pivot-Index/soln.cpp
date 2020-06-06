class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int acc = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (acc * 2 + nums[i] == sum)
                return i;
            acc += nums[i];
        }
        return -1;
    }
};
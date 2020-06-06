class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // [1,2,0]
        const int n = nums.size();
        for(int i = 0; i < n; ++i) {
            if (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                int temp = nums[i];
                nums[i] = nums[nums[i] - 1];
                nums[temp - 1] = temp;
                --i;
            }
        }
        for(int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) return i + 1;
        }
        return n + 1;
    }
};

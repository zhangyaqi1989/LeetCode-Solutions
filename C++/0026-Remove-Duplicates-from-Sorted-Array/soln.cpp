class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 0, n = nums.size();
        for(int i = 0; i < n; ++i) {
            if (i == 0 || (nums[i] != nums[i - 1]))
                nums[idx++] = nums[i];
        }
        return idx;
    }
};

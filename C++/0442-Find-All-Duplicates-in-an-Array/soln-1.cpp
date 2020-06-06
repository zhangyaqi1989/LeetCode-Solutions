class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // map num to (idx - 1)
        vector<int> dups;
        const int n = nums.size();
        for(int i = 0; i < n; ++i) {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] < 0) dups.push_back(idx + 1);
            else nums[idx] = -nums[idx];
        }
        return dups;
    }
};

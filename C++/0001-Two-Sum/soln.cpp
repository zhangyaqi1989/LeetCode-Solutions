class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> need;
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            if (need.find(nums[i]) != need.end()) return {need[nums[i]], i};
            need[target - nums[i]] = i;
        }
        return {-1, -1};
    }
};

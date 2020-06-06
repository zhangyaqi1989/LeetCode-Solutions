class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> needs;
        const int kN = nums.size();
        for(int i = 0; i < kN; ++i) {
            auto it = needs.find(nums[i]);
            if (it != needs.end()) {
                return {it->second, i};
            }
            needs.insert({target - nums[i], i});
        }
        return {};
    }
};

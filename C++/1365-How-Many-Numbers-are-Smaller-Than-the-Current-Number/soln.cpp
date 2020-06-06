class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> nums_copy(nums.begin(), nums.end());
        sort(nums_copy.begin(), nums_copy.end());
        vector<int> ans;
        for(int num : nums) {
            int cnt = upper_bound(nums_copy.begin(), nums_copy.end(), num - 1) - nums_copy.begin();
            ans.push_back(cnt);
        }
        return ans;
    }
};

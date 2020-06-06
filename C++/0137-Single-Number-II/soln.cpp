class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        return (int) ((accumulate(s.begin(), s.end(), 0.0) * 3 - accumulate(nums.begin(), nums.end(), 0.0)) / 2);
    }
};
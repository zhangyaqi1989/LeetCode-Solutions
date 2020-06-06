class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        return (3 * accumulate(s.begin(), s.end(), 0LL) - accumulate(nums.begin(), nums.end(), 0LL)) / 2;
    }
};

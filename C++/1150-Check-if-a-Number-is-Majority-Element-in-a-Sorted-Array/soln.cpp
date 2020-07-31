class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        return count_if(nums.begin(), nums.end(), [&](int x) {return x == target;}) > nums.size() / 2;
    }
};

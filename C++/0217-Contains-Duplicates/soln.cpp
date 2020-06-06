class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int num : nums) {
            if (m[num]++ > 0) return true;
        }
        return false;
    }
};

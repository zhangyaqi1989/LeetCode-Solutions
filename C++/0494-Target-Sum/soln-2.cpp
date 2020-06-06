class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        unordered_map<int, int> m;
        m[0] = 1;
        for(int num : nums) {
            unordered_map<int, int> temp;
            for(auto & item : m) {
                temp[item.first + num] += item.second;
                temp[item.first - num] += item.second;
            }
            m = temp;
        }
        return m[S];
    }
};

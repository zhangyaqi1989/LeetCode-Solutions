class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 == 1) return false;
        unordered_set<int> s = {0};
        int target = total / 2;
        for(int num : nums) {
            unordered_set<int> temp;
            for(int x : s) {
                if (x + num == target) return true;
                else if (x + num < target) {
                    temp.insert(x + num);
                }
            }
            for(int x : temp) {
                s.insert(x);
            }
        }
        return false;
    }
};

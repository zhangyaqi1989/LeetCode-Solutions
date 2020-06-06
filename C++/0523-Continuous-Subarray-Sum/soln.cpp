class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> memo;
        memo[0] = -1;
        int acc = 0;
        for(int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            acc += num;
            int r = k != 0 ? acc % k : acc;
            auto it = memo.find(r);
            if (it != memo.end()) {
                if (i > it->second + 1) return true;
            } else {
                memo[r] = i;
            } 
        }
        return false;
    }
};

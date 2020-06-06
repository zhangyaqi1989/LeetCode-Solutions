class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> seen;
        seen.insert({0, -1});
        int cur = 0, max_size = 0;
        const int kN = nums.size();
        for(int i = 0; i < kN; ++i) {
            cur += nums[i];
            auto it = seen.find(cur - k);
            if (it != seen.end()) {
                max_size = max(max_size, i - it->second);
            }
            if(seen.find(cur) == seen.end()) seen.insert({cur, i});
        }
        return max_size;
    }
};

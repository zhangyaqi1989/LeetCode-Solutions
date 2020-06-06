class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0] = -1;
        int cur = 0, n = nums.size();
        int ans = -1;
        for(int i = 0; i < n; ++i) {
            cur += nums[i];
            auto it = m.find(cur - k);
            if(it != m.end()) {
                ans = max(ans, i - it->second);
            }
            if(m.find(cur) == m.end())
                m[cur] = i;
        }
        return ans == -1 ? 0 : ans;
    }
};

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> m;
        m[0] = -1;
        int cnt = 0, ans = 0, n = nums.size();
        for(int i = 0; i < n; ++i) {
            int num = nums[i];
            if (num == 1) ++cnt;
            else --cnt;
            auto it = m.find(cnt);
            if (it == m.end()) {
                m[cnt] = i;
            } else {
                ans = max(ans, i - it->second);
            }
        }
        return ans;
    }
};

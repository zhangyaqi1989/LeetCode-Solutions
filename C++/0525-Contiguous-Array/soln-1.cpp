class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        const int MAXN = 50000;
        vector<int> seen(MAXN * 2, -MAXN);
        int cur = 0;
        seen[cur + MAXN] = -1;
        int mx = 0;
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            cur += nums[i] == 1 ? 1 : -1;
            if (seen[cur + MAXN] != -MAXN) mx = max(mx, i - seen[cur + MAXN]);
            else seen[cur + MAXN] = i;
        }
        return mx;
    }
};

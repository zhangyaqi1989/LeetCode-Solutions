class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> memo(nums.begin(), nums.end());
        int mx = 0;
        for(int num : nums) {
            if (memo.find(num - 1) == memo.end()) {
                int cur = num;
                int cnt = 0;
                while (memo.find(cur) != memo.end()) {
                    ++cnt;
                    ++cur;
                }
                mx = max(mx, cnt);
            }
        }
        return mx;
    }
};

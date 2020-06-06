class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;
        for(int x : s) {
            if (s.count(x - 1) == 0) {
                int y = x + 1;
                while (s.count(y)) ++y;
                ans = max(ans, y - x);
            }
        }
        return ans;
    }
};

class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        set<int> seen = {0};
        int cur = 0;
        int cnt = 0;
        for(int num : nums) {
            cur += num;
            if(seen.count(cur - target)) {
                ++cnt;
                seen.clear();
            }
            seen.insert(cur);
        }
        return cnt;
    }
};

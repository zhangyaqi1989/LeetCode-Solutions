class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0;
        int pre = -1, cur = 0;
        int ans = 1;
        nums.push_back(0);
        for(auto num : nums) {
            if (num == 1) {
                cnt += 1;
            } else {
                // pre = cnt;
                ans = max(ans, 1 + pre + cnt);
                pre = cnt;
                cnt = 0;
            }
        }
        return ans;
    }
};

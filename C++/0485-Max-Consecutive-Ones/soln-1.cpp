class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        nums.push_back(0);
        int cnt = 0;
        for(auto num : nums) {
            if(num == 1) {
                cnt += 1;
            } else {
                ans = max(ans, cnt);
                cnt = 0;
            }
        }
        return ans;
    }
};

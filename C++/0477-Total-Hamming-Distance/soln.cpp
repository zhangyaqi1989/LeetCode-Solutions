class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans = 0;
        int mask = 1;
        for (int i = 0; i < 32; ++i) {
            int cnt = 0;
            for(auto num : nums) {
                if(num & mask) {
                    ++cnt;
                }
            }
            mask <<= 1;
            ans += cnt * (nums.size() - cnt);
        }
        return ans;
    }
};
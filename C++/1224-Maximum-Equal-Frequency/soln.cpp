class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        int counter[100005] = {0};
        int window[100005] = {0};
        const int n = nums.size();
        int ans = 0;
        int max_freq = 0;
        for(int i = 0; i < n; ++i) {
            ++counter[nums[i]];
            --window[counter[nums[i]] - 1];
            ++window[counter[nums[i]]];
            max_freq = max(max_freq, counter[nums[i]]);
            if (max_freq == 1 || max_freq * window[max_freq] == i || (max_freq - 1) * (window[max_freq - 1] + 1) == i) {
                ans = max(ans, i + 1);
            }
        }
        return ans;
    }
};

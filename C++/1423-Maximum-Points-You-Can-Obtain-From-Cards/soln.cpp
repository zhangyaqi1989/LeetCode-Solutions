class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pres, sufs;
        pres.reserve(n + 1);
        sufs.reserve(n + 1);
        pres.push_back(0);
        sufs.push_back(0);
        for(int num : nums) {
            pres.push_back(pres.back() + num);
        }
        for(int i = n - 1; i >= 0; --i) {
            sufs.push_back(sufs.back() + nums[i]);
        }
        // k
        int ans = 0;
        for(int left = 0; left <= k; ++left) {
            ans = max(ans, pres[left] + sufs[k - left]);
        }
        return ans;
    }
};

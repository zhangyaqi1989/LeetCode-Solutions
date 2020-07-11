class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> pres = {0};
        vector<int> subs;
        int sum = 0;
        for(int num : nums) {
            sum += num;
            for(int pre : pres) {
                subs.push_back(sum - pre);
            }
            pres.push_back(sum);
        }
        sort(subs.begin(), subs.end());
        int ans = 0;
        const int kMod = 1000000007;
        for(int i = left; i <= right; ++i) {
            ans = ((long long) ans + subs[i - 1]) % kMod;
        }
        return ans;
    }
};

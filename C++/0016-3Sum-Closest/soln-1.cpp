class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int min_diff = INT_MAX;
        int best = 0;
        const int kN = nums.size();
        for(int i = 0; i < kN - 2; ++i) {
            int lo = i + 1, hi = kN - 1;
            while (lo < hi) {
                int sum = nums[i] + nums[lo] + nums[hi];
                if (sum == target) return sum;
                int diff = abs(sum - target);
                if (diff < min_diff) {
                    min_diff = diff;
                    best = sum;
                }
                if (sum > target) {
                    --hi;
                } else {
                    ++lo;
                }
            }
        }
        return best;
    }
};

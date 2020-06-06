class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> pairs;
        pairs.reserve(n);
        for(int i = 0; i < n; ++i) pairs.push_back({nums[i], i});
        sort(pairs.begin(), pairs.end());
        int lo = 0, hi = n - 1;
        while (lo < hi) {
            int s = pairs[lo].first + pairs[hi].first;
            if (s == target) return {pairs[lo].second, pairs[hi].second};
            else if (s < target) ++lo;
            else --hi;
        }
        return {-1, -1};
    }
};

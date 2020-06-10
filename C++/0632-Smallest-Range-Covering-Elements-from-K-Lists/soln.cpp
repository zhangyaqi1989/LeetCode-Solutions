class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> ans = {-100000, 100000};
        set<tuple<int, int, int>> fronts;
        int n = nums.size();
        for(int i = 0; i < n; ++i) fronts.insert({nums[i][0], 0, i});
        while (!fronts.empty()) {
            int lo, idx, lst_idx;
            tie(lo, idx, lst_idx) = *fronts.begin();
            int hi = get<0>(*fronts.rbegin());
            fronts.erase(fronts.begin());
            if (hi - lo < ans[1] - ans[0]) {
                ans[0] = lo;
                ans[1] = hi;
            }
            if (++idx == nums[lst_idx].size()) break;
            fronts.insert({nums[lst_idx][idx], idx, lst_idx});
        }
        return ans;
    }
};

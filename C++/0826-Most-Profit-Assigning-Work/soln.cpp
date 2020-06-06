class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        vector<pair<int, int>> pairs;
        for(int i = 0; i < n; ++i) {
            pairs.emplace_back(difficulty[i], profit[i]);
        }
        sort(pairs.begin(), pairs.end());
        vector<int> ds, ps;
        int cur = -1;
        for(int i = 0; i < n; ++i) {
            if (pairs[i].second > cur) {
                cur = pairs[i].second;
                ds.push_back(pairs[i].first);
                ps.push_back(pairs[i].second);
            }
        }
        int ans = 0;
        n = ds.size();
        for(int w : worker) {
            int idx = upper_bound(ds.begin(), ds.end(), w) - ds.begin();
            if (idx > 0) {
                ans += ps[idx - 1];
            }
        }
        return ans;
    }
};

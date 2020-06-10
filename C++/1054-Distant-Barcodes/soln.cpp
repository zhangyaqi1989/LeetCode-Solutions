class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& packages) {
        unordered_map<int, int> counter;
        for(int p : packages) ++counter[p];
        int n = packages.size();
        vector<int> ans(n);
        vector<int> nums;
        nums.reserve(n);
        vector<pair<int, int>> pairs;
        for(auto & p : counter) {
            pairs.push_back({-p.second, p.first});
        }
        sort(pairs.begin(), pairs.end());
        for(auto & p : pairs) {
            int cnt = -p.first;
            for(int i = 0; i < cnt; ++i) {
                nums.push_back(p.second);
            }
        }
        int idx = 0;
        for(int i = 0; i < n; i += 2) ans[i] = nums[idx++];
        for(int i = 1; i < n; i += 2) ans[i] = nums[idx++];
        return ans;
    }
};

class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        int n = values.size();
        vector<int> idxes;
        for(int i = 0; i < n; ++i) idxes.push_back(i);
        sort(idxes.begin(), idxes.end(), [&](int a, int b) {return values[a] > values[b];});
        map<int, int> used;
        int ans = 0;
        for(int idx : idxes) {
            if (used[labels[idx]] < use_limit) {
                ++used[labels[idx]];
                ans += values[idx];
                if (--num_wanted == 0) break;
            }
        }
        return ans;
    }
};

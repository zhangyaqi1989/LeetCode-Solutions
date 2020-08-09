class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        vector<vector<int>> idxes(4);
        for(size_t i = 0; i < colors.size(); ++i) {
            idxes[colors[i]].push_back(i);
        }
        vector<int> ans;
        for(const auto & query : queries) {
            auto i = query[0], color = query[1];
            auto & lst = idxes[color];
            if(lst.empty()) {
                ans.push_back(-1);
                continue;
            }
            auto it = lower_bound(lst.begin(), lst.end(), i);
            int best = 2 * colors.size();
            if(it != lst.end()) best = *it - i;
            if(it != lst.begin()) best = min(best, i - *prev(it));
            ans.push_back(best);
        }
        return ans;
    }
};

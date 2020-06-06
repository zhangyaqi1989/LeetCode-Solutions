class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        // preprocess the s
        // lowercase 26
        // rearrange and then choose up to ...
        vector<bool> ans;
        vector<vector<int>> idxes(26);
        const int n = s.length();
        for(int i = 0; i < n; ++i) {
            idxes[s[i] - 'a'].push_back(i);
        }
        for(const auto & q : queries) {
            int l = q[0], r = q[1], k = q[2];
            int nodds = 0;
            for(int i = 0; i < 26; ++i) {
                int l_idx = lower_bound(idxes[i].begin(), idxes[i].end(), l) - idxes[i].begin();
                int r_idx = upper_bound(idxes[i].begin(), idxes[i].end(), r) - idxes[i].begin();
                nodds += (r_idx - l_idx) % 2;
            }
            if ((r - l + 1) % 2 == 1) --nodds;
            ans.push_back(nodds <= k * 2);
        }
        return ans;
    }
};

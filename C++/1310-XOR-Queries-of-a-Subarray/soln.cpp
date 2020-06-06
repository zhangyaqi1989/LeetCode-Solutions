class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<vector<int>> prefixes(32, vector<int>(1, 0));
        for(int num : arr) {
            for(int i = 0; i < 32; ++i) {
                if ((num & (1 << i)) != 0) {
                    prefixes[i].push_back(prefixes[i].back() + 1);
                } else {
                    prefixes[i].push_back(prefixes[i].back());
                }
            }
        }
        vector<int> ans;
        for(const auto & q : queries) {
            int l = q[0], r = q[1];
            int v = 0;
            for(int i = 0; i < 32; ++i) {
                int cnt = (prefixes[i][r + 1] - prefixes[i][l]) % 2;
                if (cnt) v |= (1 << i);
            }
            ans.push_back(v);
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        vector<tuple<int, int, int>> tuples;
        int nw = workers.size(), nb = bikes.size();
        for(int i = 0; i < nw; ++i) {
            for(int j = 0; j < nb; ++j) {
                tuples.push_back({abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]), i, j});
            }
        }
        sort(tuples.begin(), tuples.end());
        vector<int> ans(nw, -1);
        vector<bool> wused(nw, false);
        vector<bool> bused(nb, false);
        int iw, ib, d, cnt = 0;
        for (auto & t : tuples) {
            tie(d, iw, ib) = t;
            if (!wused[iw] && !bused[ib]) {
                ans[iw] = ib;
                wused[iw] = true;
                bused[ib] = true;
                if (++cnt == nw) break;
            }
            
        }
        return ans;
    }
};

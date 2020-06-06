class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        int N = m * n;
        int parents[N] = {0};
        set<pair<int, int>> lands;
        for(int i = 0; i < N; ++i) parents[i] = i;
        int cnt = 0;
        vector<int> ans;
        int dirs[5] = {1, 0, -1, 0, 1};
        for(vector<int> & position : positions) {
            int r = position[0], c = position[1];
            // if (lands.count({r, c})) continue;
            lands.insert({r, c});
            ++cnt;
            int x = r * n + c;
            int rx = find(x, parents);
            for(int k = 0; k < 4; ++k) {
                int nr = r + dirs[k], nc = c + dirs[k + 1];
                if (0 <= nr && nr < m && 0 <= nc && nc < n && lands.count({nr, nc})) {
                    int y = nr * n + nc;
                    int ry = find(y, parents);
                    if (rx != ry) {
                        parents[ry] = rx;
                        --cnt;
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
    
    int find(int x, int parents[]) {
        return parents[x] == x ? x : parents[x] = find(parents[x], parents);
    }
};

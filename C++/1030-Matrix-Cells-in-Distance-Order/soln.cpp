class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        queue<vector<int>> q;
        q.push({r0, c0});
        int drs [4] = {0, 0, 1, -1};
        int dcs [4] = {1, -1, 0, 0};
        vector<vector<bool>> seen(R, vector<bool>(C, false));
        seen[r0][c0] = true;
        vector<vector<int>> ans;
        while (!q.empty()) {
            auto node = q.front();
            ans.push_back(node);
            q.pop();
            int r = node[0], c = node[1];
            for(int k = 0; k < 4; ++k) {
                int newr = r + drs[k], newc = c + dcs[k];
                if (0 <= newr && newr < R && 0 <= newc && newc < C && seen[newr][newc] == false) {
                    seen[newr][newc] = true;
                    q.push({newr, newc});
                }
            }
        }
        return ans;
        
    }
};

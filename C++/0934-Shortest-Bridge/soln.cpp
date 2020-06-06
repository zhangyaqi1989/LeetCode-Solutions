class Solution {
public:
    int shortestBridge(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        stack<pair<int, int>> stk;
        unordered_set<int> seen;
        queue<pair<int, int>> frontier;
        int dirs[5] = {0, 1, 0, -1, 0};
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if (A[i][j] == 1) {
                    A[i][j] = 0;
                    stk.push({i, j});
                    while (!stk.empty()) {
                        auto node = stk.top();
                        stk.pop();
                        int r = node.first, c = node.second;
                        seen.insert(r * n + c);
                        frontier.push({r, c});
                        for(int k = 0; k < 4; ++k) {
                            int dr = dirs[k], dc = dirs[k + 1];
                            int newr = r + dr, newc = c + dc;
                            if (0 <= newr && newr < m && 0 <= newc && newc < n && A[newr][newc] == 1) {
                                A[newr][newc] = 0;
                                stk.push({newr, newc});
                            }
                        }
                    }
                    
                    int step = 0;
                    while (!frontier.empty()) {
                        int sz = frontier.size();
                        for(int p = 0; p < sz; ++p) {
                            auto node = frontier.front();
                            frontier.pop();
                            int r = node.first, c = node.second;
                            if (A[r][c] == 1) return step - 1;
                            for(int k = 0; k < 4; ++k) {
                                int newr = r + dirs[k], newc = c + dirs[k + 1];
                                if (0 <= newr && newr < m && 0 <= newc && newc < n && seen.count(newr * n + newc) == 0) {
                                    seen.insert(newr * n + newc);
                                    frontier.push({newr, newc});
                                }
                            }
                        }
                        ++step;
                    }
                }
            }
        }
        return 0;
    }
};

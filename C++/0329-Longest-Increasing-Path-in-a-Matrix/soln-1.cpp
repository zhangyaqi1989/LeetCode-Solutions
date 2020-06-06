class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        const int m = matrix.size(), n = matrix[0].size();
        int mn = m * n;
        vector<int> indegrees(mn, 0);
        vector<vector<int>> outs(mn);
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                int node = i * n + j;
                if(i > 0) {
                    int nei = (i - 1) * n + j;
                    if (matrix[i - 1][j] > matrix[i][j]) {
                        ++indegrees[nei];
                        outs[node].push_back(nei);
                    } else if (matrix[i - 1][j] < matrix[i][j]) {
                        ++indegrees[node];
                        outs[nei].push_back(node);
                    }
                }
                if (j > 0) {
                    int nei = i * n + j - 1;
                    if (matrix[i][j - 1] > matrix[i][j]) {
                        ++indegrees[nei];
                        outs[node].push_back(nei);
                    } else if (matrix[i][j - 1] < matrix[i][j]) {
                        ++indegrees[node];
                        outs[nei].push_back(node);
                    }
                }
            }
        }
        vector<int> frees;
        for(int i = 0; i < mn; ++i) {
            if(!indegrees[i]) frees.push_back(i);
        }
        
        int cnt = 0;
        while (!frees.empty()) {
            vector<int> nxt_level;
            for(int u : frees) {
                for(int v : outs[u]) {
                    if(--indegrees[v] == 0) nxt_level.push_back(v);
                }
            }
            ++cnt;
            swap(frees, nxt_level);
        }
        return cnt;
    }
};

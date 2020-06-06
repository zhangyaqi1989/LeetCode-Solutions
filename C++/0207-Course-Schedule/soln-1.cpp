class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> indegrees(n, 0);
        vector<vector<int>> outs(n);
        for(vector<int> & pre : prerequisites) {
            int u = pre[1], v = pre[0];
            ++indegrees[v];
            outs[u].push_back(v);
        }
        vector<int> frees;
        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            if (!indegrees[i]) frees.push_back(i);
        }
        while(!frees.empty()) {
            int u = frees.back();
            frees.pop_back();
            ++cnt;
            for(int v : outs[u]) {
                if (--indegrees[v] == 0) frees.push_back(v);
            }
        }
        return cnt == n;
    }
};

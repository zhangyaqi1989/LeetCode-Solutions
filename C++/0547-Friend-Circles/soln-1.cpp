
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        set<int> seen;
        int cnt = 0;
        for(int i = 0; i < M.size(); ++i) {
            if (seen.find(i) == seen.end()) {
                dfs(seen, M, i);
                ++cnt;
            }
        }
        return cnt;
    }
    
    void dfs(set<int> & seen, vector<vector<int>>& M, int cur) {
        if (seen.find(cur) == seen.end()) {
            seen.insert(cur);
            vector<int> & row = M[cur];
            for(int i = 0; i < row.size(); ++i) {
                if (row[i] == 1) dfs(seen, M, i);
            }
        }
    }
};


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
    
    void dfs(set<int> & seen, vector<vector<int>>& M, int start) {
        stack<int> stk;
        stk.push(start);
        seen.insert(start);
        while (!stk.empty()) {
            int node = stk.top();
            stk.pop();
            vector<int> & row = M[node];
            for(int i = 0; i < row.size(); ++i) {
                if (row[i] == 1 && seen.find(i) == seen.end()) {
                    seen.insert(i);
                    stk.push(i);
                }
            }
        }
    }
};

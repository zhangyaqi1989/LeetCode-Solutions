int dis[] = {0, 0, 1, -1};
int djs[] = {1, -1, 0, 0};
class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return {};
        int m = matrix.size(), n = matrix[0].size();
        stack<pair<int, int>> p_front, a_front;
        vector<vector<int>> p_visited(m, vector<int>(n, 0));
        vector<vector<int>> a_visited(m, vector<int>(n, 0));
        for(int j = 0; j < n; ++j) {
            p_visited[0][j] = 1;
            p_front.push(make_pair(0, j));
        }
        for(int i = 1; i < m; ++i) {
            p_visited[i][0] = 1;
            p_front.push(make_pair(i, 0));
        }
        for(int j = 0; j < n; ++j) {
            a_visited[m - 1][j] = 1;
            a_front.push(make_pair(m - 1, j));
        }
        for(int i = 0; i < m - 1; ++i) {
            a_visited[i][n - 1] = 1;
            a_front.push(make_pair(i, n - 1));
        }
        dfs(p_front, p_visited, matrix);
        dfs(a_front, a_visited, matrix);
        vector<pair<int, int>> ans;
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j) {
                if (p_visited[i][j] == 1 && a_visited[i][j] == 1)
                    ans.emplace_back(i, j);
            }
        return ans;
    }
    
    void dfs(stack<pair<int, int>>& front, vector<vector<int>> & visited, vector<vector<int>> & matrix) {
        int m = visited.size(), n = visited[0].size();
        while(!front.empty()) {
            auto p = front.top();
            front.pop();
            int i = p.first, j = p.second;
            for(int k = 0; k < 4; ++k) {
                int di = dis[k], dj = djs[k];
                int newi = i + di, newj = j + dj;
                if (newi >= 0 && newi < m && newj >= 0 && newj < n) {
                    if(visited[newi][newj] == 0 && matrix[newi][newj] >= matrix[i][j]) {
                        visited[newi][newj] = 1;
                        front.push(make_pair(newi, newj));
                    }
                }
            }
        }
    }
};

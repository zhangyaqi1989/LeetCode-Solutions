class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<int> colors(N + 1, -1);
        vector<int> graph[N + 1] = {{}};
        for(vector<int> & p : dislikes) {
            int a = p[0], b = p[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        for(int i = 1; i <= N; ++i) {
            if (colors[i] == -1) {
                colors[i] = 0;
                if (!dfs(i, colors, graph)) return false;
            }
        }
        return true;
    }

    bool dfs(int start, vector<int> & colors, vector<int> graph[]) {
        for(int nei : graph[start]) {
            if (colors[nei] == -1) {
                colors[nei] = 1 - colors[start];
                if (!dfs(nei, colors, graph)) return false;
            } else {
                if (colors[nei] == colors[start]) return false;
            }       
        }
        return true;
    }
};

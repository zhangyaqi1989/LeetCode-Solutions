class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(const auto & edge : prerequisites) {
            int v = edge[0], u = edge[1];
            graph[u].push_back(v);
        }
        // check if this graph has cycle
        vector<int> colors(numCourses, 0);
        for(int i = 0; i < numCourses; ++i) {
            if (colors[i] == 0) {
                if (!Dfs(i, graph, &colors)) return false;
            }
        }
        return true;
    }
    
private:
    bool Dfs(int u, const vector<vector<int>> & graph, vector<int> * colors) {
        colors->at(u) = 1;
        for(int v : graph[u]) {
            if (colors->at(v) == 2) continue;
            if (colors->at(v) == 1 || !Dfs(v, graph, colors)) return false;
        }
        colors->at(u) = 2;
        return true;
    }
};

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(const auto & edge : prerequisites) {
            int u = edge[1], v = edge[0];
            graph[u].push_back(v);
        }
        vector<int> colors(numCourses, 0);
        vector<int> orders;
        for(int i = 0; i < numCourses; ++i) {
            if(colors[i] == 0) {
                if (!Dfs(i, graph, &colors, &orders)) return {};
            }
        }
        reverse(orders.begin(), orders.end());
        return orders;
    }
    
private:
    bool Dfs(int u, const vector<vector<int>> & graph, vector<int> * colors, vector<int> * orders) {
        colors->at(u) = 1;
        for(int v : graph[u]) {
            if (colors->at(v) == 2) continue;
            if (colors->at(v) == 1 || !Dfs(v, graph, colors, orders)) return false;
        }
        colors->at(u) = 2;
        orders->push_back(u);
        return true;
    }
};

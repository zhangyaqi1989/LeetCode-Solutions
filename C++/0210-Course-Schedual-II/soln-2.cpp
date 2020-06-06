class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegrees(numCourses, 0);
        vector<vector<int>> outs(numCourses);
        for(const auto & pre : prerequisites) {
            int u = pre[1], v = pre[0];
            ++indegrees[v];
            outs[u].push_back(v);
        }
        vector<int> order;
        vector<int> frees;
        for(int i = 0; i < numCourses; ++i) {
            if (!indegrees[i]) frees.push_back(i);
        }
        while (!frees.empty()) {
            vector<int> nxt_level;
            for(int u : frees) {
                order.push_back(u);
                for(int v : outs[u]) {
                    if (--indegrees[v] == 0) nxt_level.push_back(v);
                }
            }
            swap(frees, nxt_level);
        }
        if (order.size() != numCourses) order.clear();
        return order;
    }
};

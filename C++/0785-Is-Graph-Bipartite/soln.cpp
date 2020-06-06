class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int colors[n] = {0};
        for(int i = 0; i < n; ++i) {
            if (colors[i] == 0) {
                colors[i] = 1;
                stack<int> s;
                s.push(i);
                while(!s.empty()) {
                    int node = s.top();
                    s.pop();
                    int color = colors[node];
                    for(auto nei : graph[node]) {
                        if (colors[nei] == 0) {
                            colors[nei] = -1 * color;
                            s.push(nei);
                        } else {
                            if(colors[nei] == color)
                                return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};

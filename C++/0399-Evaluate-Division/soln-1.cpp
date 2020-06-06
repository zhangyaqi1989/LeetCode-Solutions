class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // 1/c * c/a ->
        unordered_map<string, unordered_map<string, double>> graph;
        int i = 0;
        for(vector<string> & eq : equations) {
            string u = eq[0], v = eq[1];
            graph[u][v] = values[i];
            graph[v][u] = 1.0 / values[i];
            ++i;
        }
        vector<double> ans;
        for(vector<string> & query : queries) {
            string start = query[0], dest = query[1];
            ans.push_back(dfs(start, dest, graph));
        }
        return ans;
    }
    
private:
    double dfs(const string & src, const string & dest, unordered_map<string, unordered_map<string, double>> & graph) {
        if (graph.find(src) == graph.end()) return -1.0;
        unordered_set<string> visited;
        stack<pair<string, double>> st;
        st.push({src, 1.0});
        while (!st.empty()) {
            auto t = st.top();
            st.pop();
            string u = t.first;
            double cur_val = t.second;
            if (u == dest) return cur_val;
            for(auto p : graph[u]) {
                string v = p.first;
                if (!visited.count(v)) {
                    visited.insert(v);
                    st.push({v, cur_val * p.second});
                }
            }
        }
        return -1.0;
    }
};

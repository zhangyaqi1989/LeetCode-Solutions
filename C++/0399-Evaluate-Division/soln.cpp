class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string, unordered_map<string, double>> graph;
        int n = values.size();
        for(int i = 0; i < n; ++i) {
            string a = equations[i].first;
            string b = equations[i].second;
            double value = values[i];
            graph[a][a] = 1.0;
            graph[b][b] = 1.0;
            graph[a][b] = value;
            graph[b][a] = 1.0 / value;
        }
        
        vector<double> ans;
        for(auto & query : queries) {
            ans.push_back(dfs(graph, query.first, query.second));
        }
        return ans;
    }
    
    double dfs(unordered_map<string, unordered_map<string, double>> & graph, string start, string target) {
        if (graph.find(start) == graph.end()) return -1.0;
        stack<pair<string, double>> stk;
        unordered_set<string> visited;
        visited.insert(start);
        stk.push({start, 1.0});
        while (!stk.empty()) {
            auto node = stk.top();
            stk.pop();
            string s = node.first;
            double cost = node.second;
            if (s == target) return cost;
            for(auto & p : graph[s]) {
                string nei = p.first;
                double v = p.second;
                if (visited.count(nei) == 0) {
                    visited.insert(nei);
                    stk.push({nei, cost * v});
                }
            }
        }
        return -1.0;
        
    }
};

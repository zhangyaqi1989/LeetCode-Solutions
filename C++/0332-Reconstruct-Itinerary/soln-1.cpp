class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> graph;
        unordered_map<string, int> counter;
        for(auto & ticket : tickets) {
            string u = ticket[0], v = ticket[1];
            graph[u].push_back(v);
            ++counter[u + v];
        }
        for(auto & p : graph) {
            sort(p.second.begin(), p.second.end());
        }
        vector<string> path;
        dfs("JFK", path, counter, graph);
        reverse(path.begin(), path.end());
        return path;
    }
    
private:
    void dfs(string node, vector<string> & path, unordered_map<string, int> & counter, unordered_map<string, vector<string>> & graph) {
        for(string nei : graph[node]) {
            if (counter[node + nei]-- > 0) {
                dfs(nei, path, counter, graph);
            }
        }
        path.push_back(node);
    }
    
};

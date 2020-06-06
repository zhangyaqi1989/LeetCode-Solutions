class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        map<string, vector<string>> graph;
        sort(tickets.rbegin(), tickets.rend());
        for(auto & p : tickets) {
            graph[p.first].push_back(p.second);
        }
        vector<string> route;
        dfs("JFK", graph, route);
        reverse(route.begin(), route.end());
        return route;
    }
    void dfs(string node, map<string, vector<string>> & graph, vector<string> & route) {
        while (!graph[node].empty()) {
            string nei = graph[node].back();
            graph[node].pop_back();
            dfs(nei, graph, route);
        }
        route.push_back(node);
    }
};

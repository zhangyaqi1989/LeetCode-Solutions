class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        unordered_map<int, vector<int>> stops;
        int n = routes.size();
        for(int i = 0; i < n; ++i) {
            for(int bus : routes[i]) {
                stops[bus].push_back(i);
            }
        }
        queue<int> frontier;
        frontier.push(S);
        unordered_set<int> seen;
        seen.insert(S);
        int step = 0;
        while (!frontier.empty()) {
            int size = frontier.size();
            for(int i = 0; i < size; ++i) {
                int stop = frontier.front();
                frontier.pop();
                if (stop == T) return step;
                for(int line : stops[stop]) {
                    for(int s : routes[line]) {
                        if(seen.find(s) == seen.end()) {
                            seen.insert(s);
                            frontier.push(s);
                        }
                    }
                    routes[line].clear();
                }                
            }
            ++step;
        }
        return -1;
    }
};

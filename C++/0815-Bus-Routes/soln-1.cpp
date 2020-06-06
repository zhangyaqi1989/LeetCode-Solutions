class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if (S == T) return 0;
        const int kN = routes.size();
        unordered_map<int, unordered_set<int>> buses;
        // BFS
        vector<int> frontier;
        bitset<1000000> levels;
        for(int i = 0; i < kN; ++i) {
            vector<int> & route = routes[i];
            for(int stop : route) {
                if (S == stop) {
                    frontier.push_back(i);
                    levels[i] = 1;
                }
                buses[stop].insert(i);
            }
        }
        int steps = 1;
        while (!frontier.empty()) {
            vector<int> next_level;
            for(int route_idx : frontier) {
                for(int stop : routes[route_idx]) {
                    if (stop == T) return steps;
                    for(int ri : buses[stop]) {
                        if (levels[ri] == 0) {
                            levels[ri] = 1;
                            next_level.push_back(ri);
                        }
                    }
                }
            }
            ++steps;
            swap(frontier, next_level);
        }
        return -1;
    }
};

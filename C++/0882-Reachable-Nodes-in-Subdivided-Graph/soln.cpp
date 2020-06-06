class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int M, int N) {
        unordered_map<int, unordered_map<int, int>> graph;
        for(vector<int> & edge : edges) {
            int i = edge[0], j = edge[1], n = edge[2];
            graph[i][j] = n;
            graph[j][i] = n;
        }
        vector<int> dists(N, INT_MAX);
        priority_queue<pair<int, int>> pq;
        pq.push({-0, 0});
        dists[0] = 0;
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            int cost = -p.first, node = p.second;
            if (cost > M) break;
            for(auto temp : graph[node]) {
                int nei = temp.first;
                if (dists[nei] > cost + temp.second + 1) {
                    dists[nei] = cost + temp.second + 1;
                    pq.push({- cost - temp.second - 1, nei});
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < N; ++i) {
            if (dists[i] <= M) ++ans;
        }
        for(vector<int> & edge : edges) {
            int i = edge[0], j = edge[1], n = edge[2];
            int a = dists[i] <= M ? M - dists[i] : 0;
            int b = dists[j] <= M ? M - dists[j] : 0;
            ans += min(a + b, n);
        }
        return ans;
    }
};

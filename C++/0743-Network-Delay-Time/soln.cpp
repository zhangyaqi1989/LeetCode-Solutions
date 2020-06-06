class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        int graph[N + 1][N + 1];
        memset(graph, 0, sizeof(graph));
        vector<int> adjs[N + 1];
        for(vector<int> & time : times) {
            int u = time[0], v = time[1], w = time[2];
            graph[u][v] = w;
            adjs[u].push_back(v);
        }
        vector<int> delays(N + 1, INT_MAX);
        queue<int> q;
        delays[K] = 0;
        q.push(K);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adjs[u]) {
                if (delays[u] + graph[u][v] < delays[v]) {
                    delays[v] = delays[u] + graph[u][v];
                    q.push(v);
                }
            }
        }
        int mx = INT_MIN;
        for(int i = 1; i <= N; ++i) {
            if (delays[i] > mx) mx = delays[i];
        }
        return mx == INT_MAX ? -1 : mx;
    }
};

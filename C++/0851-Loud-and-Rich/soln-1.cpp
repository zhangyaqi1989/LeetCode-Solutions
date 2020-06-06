class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        int degrees[n] = {0};
        vector<int> graph[n];
        for(auto & ab : richer) {
            int a = ab[0], b = ab[1];
            graph[a].push_back(b);
            ++degrees[b];
        }
        stack<int> frees;
        vector<int> ans;
        for(int i = 0; i < n; ++i) {
            ans.push_back(i);
            if (degrees[i] == 0) frees.push(i);
        }
        while (!frees.empty()) {
            int node = frees.top();
            frees.pop();
            for(int nei : graph[node]) {
                --degrees[nei];
                if (quiet[ans[node]] < quiet[ans[nei]]) ans[nei] = ans[node];
                if (degrees[nei] == 0) {
                    frees.push(nei);
                }
            }
        }
        return ans;
    }
};

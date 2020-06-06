class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        vector<pair<int, int>> cps;
        int n = Profits.size();
        for(int i = 0; i < n; ++i) cps.push_back({Capital[i], Profits[i]});
        sort(cps.begin(), cps.end());
        priority_queue<int> projects;
        int idx = 0;
        for(int i = 0; i < k; ++i) {
            while (idx < n && cps[idx].first <= W){
                projects.push(cps[idx].second);
                ++idx;
            }
            if (!projects.empty()) {
                int top = projects.top();
                projects.pop();
                W += top;
            } else break;
        }
        return W;
    }
};

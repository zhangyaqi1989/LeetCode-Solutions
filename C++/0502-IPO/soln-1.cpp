class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        const int n = Profits.size();
        vector<pair<int, int>> pairs;
        for(int i = 0; i < n; ++i) pairs.emplace_back(Capital[i], Profits[i]);
        sort(pairs.begin(), pairs.end());
        int i = 0;
        priority_queue<int> cands;
        for(int j = 0; j < k; ++j) {
            for(; i < n; ++i) {
                if (W >= pairs[i].first) cands.push(pairs[i].second);
                else break;
            }
            if (!cands.empty()) {
                W += cands.top();
                cands.pop();
            } else break;
        }
        return W;
    }
};

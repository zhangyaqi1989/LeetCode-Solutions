class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        sort(worker.begin(), worker.end());
        const int kDs = difficulty.size();
        vector<pair<int, int>> pds;
        for(int i = 0; i < kDs; ++i) {
            pds.emplace_back(profit[i], difficulty[i]);
        }
        sort(pds.begin(), pds.end(), [](const pair<int, int> & a, const pair<int, int> & b) {
            return a.second < b.second;
        });
        int j = 0, ans = 0;
        priority_queue<pair<int, int>> job_pool;
        for(int ability : worker) {
            while (j < kDs && pds[j].second <= ability) {
                job_pool.push(pds[j++]);
            }
            if (!job_pool.empty()) ans += job_pool.top().first;
        }
        return ans;
    }
};

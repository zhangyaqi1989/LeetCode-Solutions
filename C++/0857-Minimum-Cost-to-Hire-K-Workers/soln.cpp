class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        vector<pair<double, int>> workers;
        int n = quality.size();
        for(int i = 0; i < n; ++i) workers.push_back({(double) wage[i] / quality[i], quality[i]});
        double ans = DBL_MAX;
        int qsum = 0;
        priority_queue<int> pq;
        sort(workers.begin(), workers.end());
        for(int i = 0; i < n; ++i) {
            double ratio = workers[i].first;
            qsum += workers[i].second;
            pq.push(workers[i].second);
            if (pq.size() >  K) {
                qsum -= pq.top();
                pq.pop();
            }
            if (pq.size() == K) ans = min(ans, ratio * qsum);
        }
        return ans;
    }
};

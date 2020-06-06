class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        vector<pair<double, int>> arr;
        const int n = quality.size();
        for(int i = 0; i < n; ++i) {
            arr.emplace_back(wage[i] / (double) quality[i], quality[i]);
        }
        sort(arr.begin(), arr.end());
        priority_queue<int> pq;
        double mn = DBL_MAX;
        int total_quality = 0;
        for(int i = 0; i < n; ++i) {
            pq.push(arr[i].second);
            total_quality += arr[i].second;
            if (i >= K) {
                total_quality -= pq.top();
                pq.pop();
            }
            if (i >= K - 1) {
                mn = min(mn, total_quality * arr[i].first);
            }
        }
        return mn;
    }
};

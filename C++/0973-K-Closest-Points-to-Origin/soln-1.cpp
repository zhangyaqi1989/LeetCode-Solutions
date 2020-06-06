class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<pair<int, int>> pq;
        const int n = points.size();
        for(int i = 0; i < n; ++i) {
            const auto & point = points[i];
            int x = point[0], y = point[1];
            pq.push_back({x * x + y * y, i});
            push_heap(pq.begin(), pq.end());
            if (pq.size() > K) {
                pop_heap(pq.begin(), pq.end());
                pq.pop_back();
            }
        }
        vector<vector<int>> ans;
        for(auto & p : pq) {
            ans.push_back(points[p.second]);
        }
        return ans;
    }
};

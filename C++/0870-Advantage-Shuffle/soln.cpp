class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<pair<int, int>> order;
        order.reserve(n);
        vector<int> ans;
        ans.resize(n);
        sort(A.begin(), A.end());
        for(int i = 0; i < n; ++i) order.push_back({B[i], i});
        sort(order.begin(), order.end());
        int hi = n - 1;
        int i = 0;
        for(auto & p : order) {
            while (i < n && A[i] <= p.first) {
                ans[order[hi].second] = A[i];
                --hi;
                ++i;
            }
            if (i < n) {
                ans[p.second] = A[i];
                ++i;
            }
        }
        return ans;
    }
};

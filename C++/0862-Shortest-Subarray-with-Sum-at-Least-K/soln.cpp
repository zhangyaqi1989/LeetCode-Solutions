class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int n = A.size();
        vector<long long> acc(n + 1, 0LL);
        for(int i = 0; i < n; ++i) acc[i + 1] = acc[i] + A[i];
        deque<int> window;
        int cur = 0;
        int ans = n + 1;
        for(int i = 0; i < n + 1; ++i) {
            long long cur = acc[i];
            while (!window.empty() && cur - acc[window.front()] >= K) {
                ans = min(ans, i - window.front());
                window.pop_front();
            }
            while (!window.empty() && cur < acc[window.back()]) {
                window.pop_back();
            }
            window.push_back(i);
        }
        return ans == n + 1 ? -1 : ans;
    }
};

class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        int mod = 1e9 + 7;
        int n = A.size();
        int ans = 0;
        stack<int> s;
        vector<int> rights (n, 1);
        for(int i = 0; i < n; ++i) {
            while (!s.empty() && A[i] < A[s.top()]) {
                rights[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        while (!s.empty()) {
            rights[s.top()] = n - s.top();
            s.pop();
        }
        vector<int> lefts(n, 1);
        for(int i = n - 1; i >= 0; --i) {
            while(!s.empty() && A[i] <= A[s.top()]) {
                lefts[s.top()] = s.top() - i;
                s.pop();
            }
            s.push(i);
        }
        while (!s.empty()) {
            lefts[s.top()] = s.top() + 1;
            s.pop();
        }
        for(int i = 0; i < n; ++i) {
            // cout << lefts[i] << " " << rights[i] << endl;
            ans = ans + (lefts[i] * rights[i] * A[i]);
            ans %= mod;
        }
        return ans;
    }
};

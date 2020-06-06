class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int n = A.size();
        vector<int> rights(n, n);
        stack<int> stk;
        for(int i = 0; i < n; ++i) {
            while (!stk.empty() && A[i] > A[stk.top()]) {
                rights[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        
        vector<int> lefts(n, -1);
        stk = stack<int>();
        for(int i = n - 1; i >= 0; --i) {
            while (!stk.empty() && A[i] >= A[stk.top()]) {
                lefts[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            if (L <= A[i] && A[i] <= R) {
                ans += (i - lefts[i]) * (rights[i] - i);
                // cout << A[i] << " " << ans << endl;
            }
        }
        return ans;
    }
};

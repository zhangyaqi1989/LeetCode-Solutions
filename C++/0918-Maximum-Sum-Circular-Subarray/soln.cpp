class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int cur_mx, cur_mn, mx, mn, total;
        cur_mx = cur_mn = mx = mn = A[0];
        total = A[0];
        for(int i = 1; i < A.size(); ++i) {
            int num = A[i];
            total += num;
            cur_mx = max(cur_mx + num, num);
            mx = max(mx, cur_mx);
            cur_mn = min(cur_mn + num, num);
            mn = min(mn, cur_mn);
        }
        return mx < 0 ? mx : max(mx, total - mn);
    }
};
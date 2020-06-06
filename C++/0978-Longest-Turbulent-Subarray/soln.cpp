class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int inc = 1, dec = 1, ans = 1, n = A.size();
        for(int i = 1; i < n; ++i) {
            int a = A[i - 1], b = A[i];
            if (a < b) {
                tie(inc, dec) = make_tuple(dec + 1, 1);
            } else if (a > b) {
                tie(inc, dec) = make_tuple(1, inc + 1);
            } else {
                tie(inc, dec) = make_tuple(1, 1);
            }
            ans = max(ans, inc);
            ans = max(ans, dec);
        }
        return ans;
    }
};

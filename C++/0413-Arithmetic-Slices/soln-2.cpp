class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int ans = 0;
        const int kN = A.size();
        int cur = 2;
        for(int i = 2; i < kN; ++i) {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) ++cur;
            else cur = 2;
            if (cur >= 3) ans += cur - 3 + 1;
        }
        return ans;
    }
};

class Solution {
public:
    int longestMountain(vector<int>& A) {
        int n = A.size();
        int down = 0, up = 0, ans = 0;
        for(int i = 1; i < n; ++i) {
            if ((down > 0 && A[i] >= A[i - 1]) || A[i] == A[i - 1]) up = down = 0;
            down += A[i] < A[i - 1] ? 1 : 0;
            up += A[i] > A[i - 1] ? 1 : 0;
            if (up > 0 && down > 0) ans = max(ans, up + down + 1);
        }
        return ans;
    }
};

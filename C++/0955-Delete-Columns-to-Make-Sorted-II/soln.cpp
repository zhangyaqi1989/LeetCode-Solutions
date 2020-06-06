class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int n = A.size();
        vector<bool> done(n - 1, false);
        int ndone = 0;
        int m = A[0].length();
        int cnt = 0;
        for(int i = 0; i < m; ++i) {
            bool del_col = false;
            for(int j = 0; j < n - 1; ++j) {
                if (A[j][i] > A[j + 1][i] && !done[j]) {
                    del_col = true;
                    break;
                }
            }
            if (del_col) ++cnt;
            else {
                for(int j = 0; j < n - 1; ++j) {
                    if (A[j][i] < A[j + 1][i] && !done[j]) {
                        done[j] = true;
                        ++ndone;
                    }
                }
            }
            if (ndone == n - 1) break;
        }
        return cnt;
    }
};

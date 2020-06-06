class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        const int m = A.size(), n = A[0].size();
        vector<int> flags(m - 1, false);
        // check every column of A
        int cnt = 0;
        for(int j = 0; j < n; ++j) {
            bool valid = true;
            for(int i = 0; i < m - 1; ++i) {
                if(A[i][j] > A[i + 1][j] && !flags[i]) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                for(int i = 0; i < m - 1; ++i) {
                    if (A[i][j] < A[i + 1][j])
                        flags[i] = true;
                }
            } else ++cnt;
        }
        return cnt;
    }
};

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int nwords = A.size(), len = A[0].size();
        int ans = 0;
        for (int i = 0; i < len; ++i) {
            for(int j = 0; j < nwords - 1; ++j) {
                if (A[j + 1][i] < A[j][i]) {
                    ans += 1;
                    break;
                }
            }
        }
        return ans;
    }
};
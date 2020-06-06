class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int ans = n + 1;
        for(int val = 1; val <= 6; ++val) {
            int na = 0, nb = 0;
            bool valid = true;
            for(int i = 0; i < n; ++i) {
                if (A[i] != val && B[i] != val) {
                    valid = false;
                    break;
                }
                if (A[i] != val) ++na;
                if (B[i] != val) ++nb;
            }
            if (valid) ans = min(ans, min(na, nb));
        }
        return ans == n + 1 ? -1 : ans;
    }
};

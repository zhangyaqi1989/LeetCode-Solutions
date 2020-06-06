class Solution {
public:
    int strStr(string T, string P) {
        int n = T.length(), m = P.length();
        if (m == 0) return 0;
        vector<int> fail = computeFailArray(P);
        int j = 0, k = 0;
        while (j < n) {
            if (T[j] == P[k]) {
                if (k == m - 1) {
                    return j - m + 1;
                }
                ++j;
                ++k;
            } else if (k > 0) {
                k = fail[k - 1];
            } else {
                ++j;
            }
        }
        return -1;
    }
    
private:
    vector<int> computeFailArray(const string & P) {
        int m = P.length();
        vector<int> fail(m, 0);
        int j = 1;
        int k = 0;
        while (j < m) {
            if (P[j] == P[k]) {
                fail[j] = k + 1;
                ++j;
                ++k;
            } else if (k > 0) {
                k = fail[k - 1];
            } else {
                ++j;
            }
        }
        return fail;
    } 
};

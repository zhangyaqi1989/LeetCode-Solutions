class Solution {
public:
    bool buddyStrings(string A, string B) {
        int cnt = 0, nA = A.length(), nB = B.length();
        char a = ' ', b = ' ';
        for(int i = 0; i < nA; ++i) {
            if (A[i] != B[i]) {
                if (cnt == 0) {
                    a = A[i];
                    b = B[i];
                } else {
                    if (a != B[i] || b != A[i]) return false;
                }
                ++cnt;
                if (cnt > 2) return false;
            }
        }
        if (cnt == 2) return true;
        else if (cnt == 1) return false;
        else {
            int chars[256] = {0};
            for(auto ch : A) {
                ++chars[ch];
                if (chars[ch] > 1) return true;
            }
            return false;
        }
    }
};

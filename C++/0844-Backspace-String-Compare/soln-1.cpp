class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int ns = S.length(), nt = T.length();
        int i = ns - 1, j = nt - 1;
        int bs = 0, bt = 0;
        while (i >= 0 || j >= 0) {
            while (i >= 0 && (bs > 0 || S[i] == '#')) {
                if (S[i--] == '#') ++bs;
                else --bs;
            }
            while (j >= 0 && (bt > 0 || T[j] == '#')) {
                if (T[j--] == '#') ++bt;
                else --bt;
            }
            if (i >= 0 && j >= 0) {
                if (S[i] != T[j]) return false;
                --i;
                --j;
            } else {
                break;
            }
        }
        return i == j;
    }
};

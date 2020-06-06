class Solution {
public:
    string decodeAtIndex(string S, int K) {
        long long N = 0;
        int i = 0, n = S.length();
        for(; i < n; ++i) {
            char ch = S[i];
            N = isdigit(ch) ? N * (ch - '0') : N + 1;
            if (N >= K) break;
        }
        while (i >= 0) {
            if (isdigit(S[i])) {
                N /= (S[i] - '0');
                K %= N;
            } else {
                if (K % N == 0)
                    return string(1, S[i]);
                --N;
            }
            --i;
        }
        return "";
    }
};

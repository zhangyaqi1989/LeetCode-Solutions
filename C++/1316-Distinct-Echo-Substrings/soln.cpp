class Solution {
public:
    int distinctEchoSubstrings(string text) {
        const int kN = text.length();
        vector<long long> ps(kN, 0);
        const int kP = 31;
        const int kMod = 1000000009;
        ps[0] = 1;
        for(int i = 1; i < kN; ++i) {
            ps[i] = (ps[i - 1] * kP) % kMod;
        }
        vector<long long> hs(kN + 1, 0);
        for(int i = 0; i < kN; ++i) {
            hs[i + 1] = (hs[i] + (text[i] - 'a') * ps[i]) % kMod;
        }
        int cnt = 0;
        for(int l = 1; l <= kN / 2; ++l) {
            unordered_set<long long> seen;
            for(int i = 0; i < kN - 2 * l + 1; ++i) {
                long long a = (hs[i + l] + kMod - hs[i]) % kMod;
                long long b = (hs[i + l * 2] + kMod - hs[i + l]) % kMod;
                a = (a * ps[kN - 1 - i]) % kMod;
                b = (b * ps[kN - 1 - i - l]) % kMod;
                if (a == b) seen.insert(a);
            }
            cnt += seen.size();
        }
        return cnt;
    }
};

class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        int n = S.length();
        for(int i = n - 2; i >= 0; --i) {
            shifts[i] += shifts[i + 1] % 26;
        }
        for(int i = 0; i < n; ++i) {
            S[i] = (S[i] - 'a' + shifts[i]) % 26 + 'a';
        }
        return S;
    }
};

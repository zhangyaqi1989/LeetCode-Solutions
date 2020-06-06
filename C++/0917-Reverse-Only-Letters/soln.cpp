class Solution {
public:
    string reverseOnlyLetters(string S) {
        int l = 0;
        int r = S.size() - 1;
        while(l < r) {
            while (l < r && ! isalpha(S[l])) ++l;
            while (l < r && ! isalpha(S[r])) --r;
            swap(S[l], S[r]);
            ++l;
            --r;
        }
        return S;
    }
};
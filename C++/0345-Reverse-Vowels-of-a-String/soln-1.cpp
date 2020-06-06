class Solution {
public:
    string reverseVowels(string s) {
        string vowels = "AEIOUaeiou";
        int lo = 0, n = s.length(), hi = n - 1;
        while (lo < hi) {
            while (lo < hi && vowels.find(s[lo]) == string::npos) ++lo;
            while (lo < hi && vowels.find(s[hi]) == string::npos) --hi;
            if (lo < hi) swap(s[lo++], s[hi--]);
        }
        return s;
    }
};

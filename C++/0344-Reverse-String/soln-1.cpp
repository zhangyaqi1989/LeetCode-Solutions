class Solution {
public:
    void reverseString(vector<char>& s) {
        int lo = 0, n = s.size(), hi = n  - 1;
        while (lo < hi) {
            swap(s[lo++], s[hi--]);
        }
    }
};

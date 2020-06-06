class Solution {
public:
    string reverseStr(string s, int k) {
        string ans = "";
        int i = 0;
        int n = s.length();
        while (i < n) {
            string left = s.substr(i, k);
            reverse(left.begin(), left.end());
            ans += left;
            i += k;
            if (i >= n) break;
            ans += s.substr(i, k);
            i += k;
        }
        return ans;
    }
};

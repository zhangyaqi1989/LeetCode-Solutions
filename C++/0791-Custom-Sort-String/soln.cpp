class Solution {
public:
    string customSortString(string S, string T) {
        int counter[26] = {0};
        for(char ch : T) ++counter[ch - 'a'];
        string ans = "";
        for(char ch : S) {
            int n = counter[ch - 'a'];
            while (n-- > 0) {
                ans += ch;
                --counter[ch - 'a'];
            }
        }
        for(int i = 0; i < 26; ++i) {
            int n = counter[i];
            for(int j = 0; j < n; ++j) ans += ('a' + i);
        }
        return ans;
    }
};

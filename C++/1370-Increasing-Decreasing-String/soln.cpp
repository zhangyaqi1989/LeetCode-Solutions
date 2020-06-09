class Solution {
public:
    string sortString(string s) {
        vector<int> counter(26, 0);
        for(char ch : s) ++counter[ch - 'a'];
        string ans = "";
        while(ans.length() < s.length()) {
            for(int i = 0; i < 26; ++i) {
                if(counter[i]) {
                    --counter[i];
                    ans += (char)('a' + i);
                }
            }
            for(int i = 25; i >= 0; --i) {
                if(counter[i]) {
                    --counter[i];
                    ans += (char)('a' + i);
                }
            }
        }
        return ans;
    }
};

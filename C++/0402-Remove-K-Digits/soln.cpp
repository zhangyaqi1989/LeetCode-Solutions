class Solution {
public:
    string removeKdigits(string num, int k) {
        // 1432219
        vector<char> s;
        for(auto ch : num) {
            while (k > 0 && !s.empty() && ch < s[s.size() - 1]) {
                --k;
                s.pop_back();               
            }
            s.push_back(ch);
        }
        string ans = "";
        for(int i = 0; i < k; ++i) {
            s.pop_back();
        }
        int i = 0;
        while (i < s.size() && s[i] == '0') ++i;
        for(;i < s.size(); ++i) ans += s[i];
        return ans.size() == 0 ? "0" : ans ;
    }
};

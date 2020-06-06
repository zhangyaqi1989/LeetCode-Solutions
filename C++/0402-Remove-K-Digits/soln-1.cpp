class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> picked;
        for(char ch : num) {
            while (k > 0 && !picked.empty() && picked.back() > ch) {
                picked.pop_back();
                --k;
            }
            picked.push_back(ch);
        }
        string ans = "";
        for(int i = 0; i < picked.size() - k; ++i) {
            ans += picked[i];
        }
        int i = 0;
        while (i < ans.length() && ans[i] == '0') ++i;
        ans = ans.substr(i);
        return ans.empty() ? "0" : ans;
    }
};

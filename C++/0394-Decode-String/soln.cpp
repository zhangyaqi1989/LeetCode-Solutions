class Solution {
public:
    string decodeString(string s) {
        vector<pair<int, string>> ans = {{1, ""}};
        int num = 0;
        for(char ch : s) {
            if (isdigit(ch)) {
                num = num * 10 + ch - '0';
            } else if (ch == '[') {
                ans.push_back({num, ""});
                num = 0;
            } else if (ch == ']') {
                auto p = ans.back();
                ans.pop_back();
                for(int i = 0; i < p.first; ++i) {
                    ans.back().second += p.second;
                }
            } else {
                ans.back().second += ch;
            }
        }
        return ans.back().second;
    }
};

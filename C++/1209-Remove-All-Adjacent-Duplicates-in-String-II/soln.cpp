class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> stk;
        for(char ch : s) {
            if (stk.empty() || stk.back().first != ch) {
                stk.push_back({ch, 1});
            } else {
                stk.back().second = (stk.back().second + 1) % k;
                if (stk.back().second == 0) stk.pop_back();
            }
        }
        string ans = "";
        for(auto & p : stk) {
            ans += string(p.second, p.first);
        }
        return ans;
    }
};

class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        set<string> ans;
        for(int b = 2; b <= n; ++b) {
            for(int a = 1; a < b; ++a) {
                int gcd = __gcd(a, b);
                ans.insert(to_string(a / gcd) + "/" + to_string(b / gcd));
            }
        }
        if (ans.empty()) return {};
        vector<string> ret(ans.begin(), ans.end());
        return ret;
    }
};

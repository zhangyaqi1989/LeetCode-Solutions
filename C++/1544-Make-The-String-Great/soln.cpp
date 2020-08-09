class Solution {
public:
    string makeGood(string s) {
        const int kDiff = 'a' - 'A';
        string ans;
        for(char ch : s) {
            if(!ans.empty() && abs(ans.back() - ch) == kDiff) {
                ans.pop_back();
            } else {
                ans += ch;
            }
        }
        return ans;
    }
};

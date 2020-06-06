class Solution {
public:
    string makeLargestSpecial(string S) {
        return helper(S, 0, (int) S.length());
    }
    
private:
    string helper(const string & s, int lo, int hi) {
        vector<string> tokens;
        int opens = 0, i = lo;
        for(int j = lo; j < hi; ++j) {
            opens += (s[j] == '1' ? 1 : -1);
            if (opens == 0) {
                tokens.push_back("1" + helper(s, i + 1, j) + "0");
                i = j + 1;
            }
        }
        sort(tokens.rbegin(), tokens.rend());
        string ans;
        for(const auto & item : tokens) ans += item;
        return ans;
    }
};

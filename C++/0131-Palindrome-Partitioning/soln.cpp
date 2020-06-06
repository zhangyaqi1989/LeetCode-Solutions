class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> sub;
        helper(s, 0, ans, sub);
        return ans;
    }
    
    void helper(string s, int idx, vector<vector<string>> & ans, vector<string> & sub) {
        if (idx == s.length()) {
            ans.push_back(sub);
        } else {
            for(int i = idx + 1; i < s.length() + 1; ++i) {
                if(isPalindrome(s.substr(idx, i - idx))) {
                    sub.push_back(s.substr(idx, i - idx));
                    helper(s, i, ans, sub);
                    sub.pop_back();
                }
            }
        }
        
    }
    
    bool isPalindrome(string s) {
        int n = s.length();
        for(int i = 0; i < n / 2; ++i) {
            if (s[i] != s[n - 1 - i]) return false;
        }
        return true;
    }
};

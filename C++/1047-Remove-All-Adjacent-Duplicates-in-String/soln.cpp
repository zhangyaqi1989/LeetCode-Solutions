class Solution {
public:
    string removeDuplicates(string s) {
        while (true) {
            string news = helper(s);
            if (news.length() == s.length()) break;
            swap(news, s);
        }
        return s;
    }
    
    string helper(string s) {
        int i = 0, n = s.length();
        string ans = "";
        for(int j = 0; j < n; ++j) {
            if (s[j] != s[i]) {
                if ((j - i) % 2) ans += s[i];
                i = j;
            }
        }
        if ((n - i) % 2) ans += s[i];
        return ans;
    }
};

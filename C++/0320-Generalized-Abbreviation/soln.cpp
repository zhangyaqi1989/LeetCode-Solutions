class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> ans;
        int n = word.length();
        for(int i = 0; i < (1 << n); ++i) {
            string temp = "";
            for(int j = 0; j < n; ++j) {
                if ((i & (1 << j)) == 0) {
                    temp += "#";
                } else {
                    temp += word[j];
                }
            }
            // cout << temp << endl;
            ans.push_back(decode(temp));
        }
        return ans;
    }
    
    string decode(string word) {
        int cur = 0;
        string ans = "";
        for(char ch : word) {
            if (ch != '#') {
                if (cur > 0) ans += to_string(cur);
                ans += ch;
                cur = 0;
            } else 
                ++cur;
        }
        if (cur > 0) ans += to_string(cur);
        return ans;
    }
    
};

class Solution {
public:
    vector<string> ambiguousCoordinates(string S) {
        S = S.substr(1, S.length() - 2);
        int n = S.length();
        vector<string> ans;
        for(int i = 1; i < n; ++i) {
            string left = S.substr(0, i);
            string right = S.substr(i);
            for(string l : toNums(left))
                for(string r : toNums(right)) {
                    ans.push_back("(" + l + ", " + r + ")");
                }
        }
        return ans;
    }
    
    vector<string> toNums(string s) {
        vector<string> ans;
        int n = s.length();
        if (s.back() != '0') {
            for(int i = 1; i < n; ++i) {
                if (s[0] == '0' && i > 1) continue;
                bool valid = false;
                for(int j = i; j < n; ++j) {
                    if (s[j] != '0') {
                        valid = true;
                        break;
                    }
                }
                if (valid) ans.push_back(s.substr(0, i) + "." + s.substr(i));
            }
        }
        if(s[0] != '0' || n == 1) ans.push_back(s);
        return ans;
    }
};

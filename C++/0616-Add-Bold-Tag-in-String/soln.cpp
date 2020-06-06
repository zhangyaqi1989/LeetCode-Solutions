class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        vector<int> tags (s.size(), 0);
        for(auto word : dict)
        {
            int len = word.size();
            for(int i = 0; i < (int) s.size() - len + 1; ++i)
            {
                if(s.substr(i, len) == word)
                {
                    for(int j = i; j < i + len; ++j)
                        tags[j] = 1;
                }
            }
        }
        string res = "";
        for(int i = 0; i < s.size(); ++i)
        {
            if(tags[i] && (i == 0 || tags[i - 1] == 0))
                res += "<b>";
            res += s[i];
            if (tags[i] && (i == s.size() - 1 || tags[i + 1] == 0))
                res += "</b>";
        }
        return res;
    }
};
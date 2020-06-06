class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        string ans = "";
        int i = 0;
        bool flag = true;
        while(flag)
        {
            unordered_set<char> s;
            for(auto str : strs)
            {
                if(i >= str.size())
                {
                    flag = false;
                    break;
                }
                s.insert(str[i]);
            }
            if(flag && s.size() == 1) ans += strs[0][i];
            else flag = false;
            ++i;
        }
        return ans;
    }
};
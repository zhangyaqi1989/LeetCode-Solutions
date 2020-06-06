class Solution {
public:
    string reorganizeString(string S) {
        int chars[26] = {0};
        for(char ch : S) ++chars[ch - 'a'];
        priority_queue<pair<int, char>> lefts;
        for(char ch = 'a'; ch <= 'z'; ++ch) {
            if (chars[ch - 'a']) lefts.push({chars[ch - 'a'], ch});
        }
        string ans;
        pair<int, char> temp = {0, 'a'};
        while (!lefts.empty()) {
            auto p = lefts.top();
            lefts.pop();
            ans += p.second;
            --p.first;
            if (temp.first > 0) {
                lefts.push(temp);
            }
            temp = p;
        }
        return ans.length() == S.length() ? ans : "";
    }
};

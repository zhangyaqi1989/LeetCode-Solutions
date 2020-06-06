class Solution {
public:
    vector<int> diStringMatch(string S) {
        int l = 0, r = S.size();
        vector<int> ans;
        for (auto ch : S) {
            if(ch == 'I') ans.push_back(l++);
            else ans.push_back(r--);
        }
        ans.push_back(l);
        return ans;
    }
};
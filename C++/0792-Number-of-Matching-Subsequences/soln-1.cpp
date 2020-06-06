class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        int cnt = 0, n = S.length();
        vector<string> pres[26];
        for(string word : words) {
            pres[word[0] - 'a'].push_back(word.substr(1));
        }
        for(int i = 0; i < n; ++i) {
            int idx = S[i] - 'a';
            vector<string> temp = pres[idx];
            if (temp.size() != 0) {
                pres[idx].clear();
                for(auto & item : temp) {
                    if(item.length() == 0) ++cnt;
                    else pres[item[0] - 'a'].push_back(item.substr(1));
                }
            }
        }
        return cnt;
    }
};

class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<char> cand;
        vector<string> ans;
        Dfs(0, word, &cand, &ans);
        return ans;
    }
    
    
private:
    void Dfs(int i, const string & word, vector<char> * cand, vector<string> * ans) {
        if (i == word.length()) {
            ans->push_back(ToString(*cand));
        } else {
            cand->push_back(word[i]);
            Dfs(i + 1, word, cand, ans);
            cand->pop_back();
            
            cand->push_back('#');
            Dfs(i + 1, word, cand, ans);
            cand->pop_back();
        }
    }
    
    string ToString(const vector<char> & cand) {
        string ans;
        int cnt = 0;
        for(char ch : cand) {
            if (ch == '#') {
                ++cnt;
            } else {
                if(cnt) ans += to_string(cnt);
                cnt = 0;
                ans += ch;
            }
        }
        if (cnt) ans += to_string(cnt);
        return ans;
    }
};

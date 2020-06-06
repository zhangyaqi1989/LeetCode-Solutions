class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans(queries.size(), false);
        for(int i = 0; i < queries.size(); ++i) {
            string word = queries[i];
            if (valid(word, pattern)) ans[i] = true; 
        }
        return ans;
    }
    
    bool valid(string & word, string pattern) {
        int i = 0, n = pattern.length();
        int j = 0;
        for(; j < word.length(); ++j) {
            if (word[j] == pattern[i]) {
                i += 1;
                if (i == n) break;
            } else {
                if (word[j] >= 'A' && word[j] <= 'Z') return false;
            }
        }
        if (i != n) return false;
        // cout << i << " " << j <<  endl;
        for(int k = j + 1; k < word.length(); ++k) {
            if (word[k] >= 'A' && word[k] <= 'Z') return false;
        }
        return true;
        
    }
};

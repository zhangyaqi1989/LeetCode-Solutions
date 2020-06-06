
class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        int cnt = 0;
        for(string word : words) {
            if (isSubsequence(S, word)) ++cnt;
        }
        return cnt;
    }
    
    int isSubsequence(string & S, string & word) {
        int n = S.size(), m = word.size();
        if (m > n) return false;
        int j = 0;
        for(int i = 0; i < n; ++i) {
            if (S[i] == word[j]) {
                ++j;
                if (j == m) return true;
            }
        }
        return false;
    }
};

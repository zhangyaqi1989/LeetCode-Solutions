class Solution {
public:
    int minimumDistance(string word) {
        vector<vector<int>> memo(300, vector<int>(26 * 26, -1));
        int ans = INT_MAX;
        for(char f1 = 'A'; f1 <= 'Z'; ++f1) {
            for(char f2 = 'A'; f2 <= 'Z'; ++f2) {
                ans = min(ans, Dfs(word, 0, f1, f2, &memo));
            }
        }
        return ans;
    }
    
private:
    int Distance(char c1, char c2) {
        int i1 = c1 - 'A', i2 = c2 - 'A';
        return abs(i1 / 6 - i2 / 6) + abs(i1 % 6 - i2 % 6);
    }
    int Dfs(const string & word, int idx, char f1, char f2, vector<vector<int>> * memo) {
        const int kN = word.length();
        if (idx == kN) return 0;
        int col = (f1 - 'A') * 26 + (f2 - 'A');
        if ((*memo)[idx][col] != -1) {
            return (*memo)[idx][col];
        }
        char c = word[idx];
        int ans = min(Distance(c, f1) + Dfs(word, idx + 1, c, f2, memo), Distance(c, f2) + Dfs(word, idx + 1, f1, c, memo));
        (*memo)[idx][col] = ans;
        return ans;
    }
};

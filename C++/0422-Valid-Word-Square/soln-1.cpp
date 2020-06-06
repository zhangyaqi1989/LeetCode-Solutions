class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        int n = words.size();
        for(int i = 0; i < n; ++i) {
            // i-th row equals to i-th column
            for(int j = 0; j < words[i].length(); ++j) {
                // words[i][j] == words[j][i]
                if (j >= n || i >= words[j].length() || words[i][j] != words[j][i]) return false;
            }
        }
        return true;
    }
};

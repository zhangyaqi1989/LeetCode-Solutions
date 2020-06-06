class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int i1 = -1, i2 = -1, ans = INT_MAX, n = words.size();
        for(int i = 0; i < n; ++i) {
            string word = words[i];
            if (word1 == word) {
                i1 = i;
            } else if (word2 == word) {
                i2 = i;
            }
            if (i1 != -1 && i2 != -1) {
                ans = min(ans, abs(i1 - i2));
            }
        }
        return ans;
    }
};

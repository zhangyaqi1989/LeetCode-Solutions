class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        const int kN = words.size();
        int pre_i1 = -1, pre_i2 = -1;
        int best = kN + 1;
        bool equal = word1 == word2;
        for(int i = 0; i < kN; ++i) {
            if (words[i] == word1) {
                if (equal) {
                    if (pre_i1 != -1) {
                        best = min(best, i - pre_i1);
                    }
                } else {
                    if (pre_i2 != -1) {
                        best = min(best, i - pre_i2);
                    }
                }
                pre_i1 = i;
            } else if (words[i] == word2) {
                if (pre_i1 != -1) {
                    best = min(best, i - pre_i1);
                }
                pre_i2 = i;
            }
        }
        return best;
    }
};

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        const int kN = words.size();
        sort(words.begin(), words.end(), [](const string & a, const string & b) {
            return a.length() < b.length();
        });
        vector<int> dp(kN, 1);
        for(int i = 1; i < kN; ++i) {
            for(int j = i - 1; j >= 0; --j) {
                if (words[i].length() == words[j].length()) continue;
                if (words[i].length() > words[j].length() + 1) break;
                if (IsPredecessor(words, j, i)) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
    
private:
    // returns true if words[a] is predecessor of words[b]
    bool IsPredecessor(const vector<string> & words, int a, int b) {
        const string & P = words[a];
        const string & S = words[b];
        const int kNP = P.length(), kNS = S.length();
        int j = 0;
        for(int i = 0; i < kNS; ++i) {
            if (S[i] == P[j]) {
                if (++j == kNP) return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        // tokens P
        // if has at least token[i] power, play face up, losing token[i] power, gain one point
        // if at least point, play the token face down, gain token[i] power and lose one point
        sort(tokens.begin(), tokens.end());
        int n = tokens.size();
        int lo = 0, hi = n - 1;
        int points = 0;
        while (lo <= hi) {
            if (P >= tokens[lo]) {
                P -= tokens[lo];
                ++points;
                ++lo;
            } else if (points > 0 && hi > lo) {
                P += tokens[hi];
                --points;
                --hi;
            } else {
                break;
            }
        }
        return points;
    }
};

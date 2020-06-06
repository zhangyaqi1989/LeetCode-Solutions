class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& D, int N) {
        int M = N + 1;
        vector<int> digits;
        do {
            digits.push_back(M % 10);
        } while (M /= 10);
        reverse(digits.begin(), digits.end());
        int ans = 0;
        int n = digits.size();
        int m = D.size();
        for(int i = 1; i < n; ++i) {
            ans += pow(m, i);
        }
        vector<bool> cands(10, false);
        for(auto item : D) cands[stoi(item)] = true;
        for(int i = 0; i < n; ++i) {
            for(auto item : D) {
                int x = stoi(item);
                if (x >= digits[i]) break;
                ans += pow(m, n - 1 - i);
            }
            if (!cands[digits[i]]) break;
        }
        return ans;
    }
};

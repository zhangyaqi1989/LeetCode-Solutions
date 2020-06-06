class Solution {
public:
    int numDupDigitsAtMostN(int N) {
        int x = N + 1;
        vector<int> digits;
        do {
            digits.push_back(x % 10);
        } while (x /= 10);
        reverse(digits.begin(), digits.end());
        int uniques = 0;
        int cur = 9;
        int n = digits.size();
        for(int i = 1; i < n; ++i) {
            uniques += cur;
            if (i + 1 < n) cur *= 10 - i;
        }
        vector<bool> seen(10, false);
        for(int i = 0; i < n; ++i) {
            int d = digits[i];
            int start = i == 0 ? 1 : 0;
            for(int x = start; x < d; ++x) {
                if (seen[x]) continue;
                uniques += helper(9 - i, n - i - 1);
            }
            if (seen[d]) break;
            seen[d] = true;
        }
        return N - uniques;
    }
    
    /* number of ways to form */
    int helper(int m, int n) {
        return n == 0 ? 1 : m * helper(m - 1, n - 1);
    }
};

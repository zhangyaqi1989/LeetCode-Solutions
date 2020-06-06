class Solution {
public:
    int numDupDigitsAtMostN(int N) {
        int M = N + 1;
        vector<int> digits;
        while (M) {
            digits.push_back(M % 10);
            M /= 10;
        }
        reverse(digits.begin(), digits.end());
        int n = digits.size();
        int uniques = 0;
        for(int i = 1; i < n; ++i) uniques += 9 * pick(9, i - 1);
        int used[10] = {0};
        for(int i = 0; i < n; ++i) {
            int start = i == 0 ? 1 : 0;
            for(int y = start; y < digits[i]; ++y) {
                if(used[y] == 1) continue;
                uniques += pick(9 - i, n - i - 1);
            }
            if (used[digits[i]] == 1) break;
            used[digits[i]] = 1;
        }
        return N - uniques;
        
    }
    
    int pick(int m, int n) {
        int ans = 1;
        for(int i = 0; i < n; ++i) {
            ans *= m;
            --m;
        }
        return ans;
    }
};

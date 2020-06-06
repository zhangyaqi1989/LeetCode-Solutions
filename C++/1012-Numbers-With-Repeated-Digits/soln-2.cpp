class Solution {
public:
    int numDupDigitsAtMostN(int N) {
        // number < N + 1
        ++N;
        int width = to_string(N).length();
        int nuniques = 0;
        for(int i = 1; i < width; ++i) {
            nuniques += ComputeUniques(i);
        }
        // less than N, uniques
        vector<int> digits;
        int temp = N;
        while (temp) {
            digits.push_back(temp % 10);
            temp /= 10;
        }
        reverse(digits.begin(), digits.end());
        vector<bool> seen(10, false);
        int n = digits.size();
        for(int i = 0; i < n; ++i) {
            int d = digits[i];
            int start = (i == 0 ? 1 : 0);
            for(int j = start; j < d; ++j) {
                if (seen[j]) continue;
                nuniques += Pick(9 - i, n - 1 - i);
            }
            if (seen[d]) break;
            seen[d] = true;
        }
        return N - 1 - nuniques;
    }
    
private:
    int ComputeUniques(int width) {
        int ans = 9;
        int left = 9;
        while(width-- > 1) {
            ans *= left--;
        }
        return ans;
    }
    
    // how many ways to pick m from n
    int Pick(int n, int m) {
        int ans = 1;
        while (m-- > 0) {
            ans *= n--;
        }
        return ans;
    }
};

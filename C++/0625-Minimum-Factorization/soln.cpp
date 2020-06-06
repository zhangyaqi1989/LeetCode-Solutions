class Solution {
public:
    int smallestFactorization(int a) {
        if (a <= 9) return a;
        vector<int> digits;
        for(int d = 9; d > 1; --d) {
            while (a > 1 && a % d == 0) {
                a /= d;
                digits.push_back(d);
                if (digits.size() > 10) return 0;
            }
            if (a == 1) break;
        }
        if (a > 1) return 0;
        long long ans = 0;
        int n = digits.size();
        for(int i = n - 1; i >= 0; --i) {
            ans = ans * 10 + digits[i];
            if (ans > INT_MAX) return 0;
        }
        return ans;
    }
};

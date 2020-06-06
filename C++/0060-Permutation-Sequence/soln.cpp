class Solution {
public:
    string getPermutation(int n, int k) {
        string digits = "123456789";
        digits = digits.substr(0, n);
        int units = 1;
        for(int i = 2; i < n; i++) units *= i;
        string ans = "";
        k -= 1;
        for(int i = 0; i < n; ++i) {
            int q = k / units;
            ans += digits[q];
            k %= units;
            if (i < n - 1) units /= (n - 1 - i);
            digits = digits.substr(0, q) + digits.substr(q + 1);
            // cout << q << digits << endl;
        }
        return ans;
    }
};

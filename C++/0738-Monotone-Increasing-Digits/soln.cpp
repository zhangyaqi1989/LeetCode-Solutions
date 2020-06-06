class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string str = to_string(N);
        vector<int> digits;
        for(char ch : str) digits.push_back(ch - '0');
        int n = digits.size();
        int end = n;
        for(int i = n - 1; i > 0; --i) {
            if (digits[i - 1] > digits[i]) {
                --digits[i - 1];
                end = i;
            }
        }
        for(int i = end; i < n; ++i) {
            digits[i] = 9;
        }
        int ans = 0;
        for(int digit : digits) {
            ans = ans * 10 + digit;
        }
        return ans;
    }
};

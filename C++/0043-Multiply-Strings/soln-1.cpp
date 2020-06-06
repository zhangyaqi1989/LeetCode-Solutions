class Solution {
public:
    string multiply(string num1, string num2) {
        const int n1 = num1.length(), n2 = num2.length();
        vector<int> digits(n1 + n2, 0);
        for(int i = n1 - 1; i >= 0; --i) {
            int d1 = num1[i] - '0';
            int shift = n1 - 1 - i;
            int carry = 0;
            for(int j = n2 - 1; j >= 0; --j) {
                int d2 = num2[j] - '0';
                int v = d2 * d1 + carry;
                carry = v / 10;
                digits[shift + n2 - 1 - j] += v % 10;
            }
            if (carry) {
                digits[shift + n2] += carry;
            }
            
        }
        int carry = 0;
        for(int i = 0; i < digits.size(); ++i) {
            int v = digits[i] + carry;
            digits[i] = v % 10;
            carry = v / 10;
        }
        string ans;
        int i = (int) digits.size() - 1;
        while (i >= 0 && digits[i] == 0) --i;
        while (i >= 0) ans += to_string(digits[i--]);
        return ans.empty() ? "0" : ans;
    }
};

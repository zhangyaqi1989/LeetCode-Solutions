class Solution {
public:
    string multiply(string num1, string num2) {
        // "123" "456"
        vector<int> digits(400, 0);
        int start = 0;
        int n1 = num1.length(), n2 = num2.length();
        for(int i = n2 - 1; i >= 0; --i) {
            int d2 = num2[i] - '0';
            // cout << d2 << endl;
            int carry = 0;
            int start = n2 - 1 - i;
            for(int j = n1 - 1; j >= 0; --j) {
                int val = d2 * (num1[j] - '0') + carry;
                carry = val / 10;
                digits[start++] += val % 10;
                // cout << val % 10 << endl;
            }
            if (carry > 0) digits[start] += carry; 
        }
        int idx = 0;
        int carry = 0;
        for(int i = 0; i < digits.size(); ++i) {
            int val = digits[i] + carry;
            carry = val / 10;
            val = val % 10;
            digits[i] = val;
            if (val > 0) idx = i;
        }
        digits.resize(idx + 1);
        string ans = "";
        for(auto it = digits.rbegin(); it != digits.rend(); ++it) {
            ans += to_string(*it);
        }
        return ans;
    }
};

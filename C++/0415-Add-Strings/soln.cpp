class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans = "";
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;
        while (i >= 0 || j >= 0 || carry != 0)
        {
            int val1 = i >= 0 ? num1[i] - '0' : 0;
            int val2 = j >= 0 ? num2[j] - '0' : 0;
            --i;
            --j;
            int val = val1 + val2 + carry;
            carry = val / 10;
            ans = string(1, '0' + (val % 10)) + ans;
        }
        return ans;
    }
};

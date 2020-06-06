class Solution {
public:
    string addStrings(string num1, string num2) {
        const int kN1 = num1.length(), kN2 = num2.length();
        int i = kN1 - 1, j = kN2 - 1;
        int carry = 0;
        string sum;
        while (i >= 0 || j >= 0 || carry) {
            int v1 = i >= 0 ? num1[i--] - '0' : 0;
            int v2 = j >= 0 ? num2[j--] - '0' : 0;
            int v = v1 + v2 + carry;
            sum += static_cast<char> ('0' + v % 10);
            carry = v / 10;
        }
        reverse(sum.begin(), sum.end());
        return sum;
    }
};

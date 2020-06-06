class Solution {
    public String addStrings(String num1, String num2) {
        int carry = 0;
        StringBuilder sb = new StringBuilder();
        int n1 = num1.length(), n2 = num2.length(), i1 = n1 - 1, i2 = n2 - 1;
        while (carry != 0 || i1 >= 0 || i2 >= 0) {
            if (i1 >= 0) carry += num1.charAt(i1--) - '0';
            if (i2 >= 0) carry += num2.charAt(i2--) - '0';
            sb.append(carry % 10);
            carry /= 10;
        }
        return sb.reverse().toString();
    }
}

class Solution {
public:
    int myAtoi(string str) {
        long ans = 0;
        int sign = 1;
        for(int i = 0; i < str.size();) {
            while (i < str.size() && str[i] == ' ') ++i;
            if (i == str.size()) return 0;
            if (str[i] == '+' || str[i] == '-') {
                if (str[i] == '-') sign = -1;
                ++i;
            }
            while ('0' <= str[i] && str[i] <= '9') {
                ans = ans * 10 + (str[i++] - '0');
                if (ans * sign > INT_MAX) return INT_MAX;
                if (ans * sign < INT_MIN) return INT_MIN;
            }
            break;
        }
        return ans * sign;
    }
};

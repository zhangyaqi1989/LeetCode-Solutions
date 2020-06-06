class Solution {
public:
    int myAtoi(string str) {
        const int n = str.length();
        int i = 0;
        while(i < n && str[i] == ' ') ++i;
        int sign = 1;
        if (i < n && (str[i] == '+' || str[i] == '-')) {
            sign = str[i] == '-' ? -1 : 1;
            ++i;
        }
        long long num = 0;
        while(i < n && (str[i] >= '0' && str[i] <= '9')) {
            num = num * 10 + (str[i] - '0');
            if (sign * num >= INT_MAX) return INT_MAX;
            else if (sign * num <= INT_MIN) return INT_MIN;
            ++i;
        }
        return num * sign;
    }
};

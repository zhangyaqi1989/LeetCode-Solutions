class Solution {
public:
    int myAtoi(string str) {
        int sign = 1, i = str.find_first_not_of(' ');
        if (i == -1) return 0;
        if (str[i] == '+' || str[i] == '-')
            sign = (str[i++] == '+' ? 1 : -1);
        long res = 0;
        while (i < str.length() && isdigit(str[i])) {
            res = 10 * res + str[i] - '0';
            if (res > INT_MAX) 
                return sign == 1 ? INT_MAX : INT_MIN;
            i++;
        }
        return (int) (sign * res);
    }
};

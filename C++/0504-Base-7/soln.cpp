class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        string ans = "";
        int sign = num < 0 ? -1 : 1;
        num = abs(num);
        while(num)
        {
            int val = num % 7;
            num /= 7;
            ans = to_string(val) + ans;
        }
        if (sign == -1) ans = "-" + ans;
        return ans;
    }
};

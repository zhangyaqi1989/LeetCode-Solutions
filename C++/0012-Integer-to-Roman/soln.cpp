class Solution {
public:
    string intToRoman(int num) {
        string symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int units[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        int n = 13;
        string ans = "";
        for(int i = 0; i < n; ++i) {
            int unit = units[i];
            string symbol = symbols[i];
            while (num >= unit) {
                for(int j = 0; j < num / unit; ++j) {
                    ans += symbol;
                }
                num %= unit;
            }
            if(num == 0) return ans;
        }
        return ans;
    }
};

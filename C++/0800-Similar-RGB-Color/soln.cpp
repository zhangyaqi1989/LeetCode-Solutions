class Solution {
public:
    string similarRGB(string color) {
        string digits = "0123456789abcdef";
        string ans = "#";
        for(int i = 1; i < 7; i += 2) {
            int num = stoi(color.substr(i, 2), nullptr, 16);
            int idx = 0, diff = num;
            for(int j = 1; j < 16; ++j) {
                if (abs(num - (j * 16 + j)) < diff) {
                    diff = abs(num - (j * 16 + j));
                    idx = j;
                }
            }
            ans += string(2, digits[idx]);
        }
        return ans;
        
    }
};

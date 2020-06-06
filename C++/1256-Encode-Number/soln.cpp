class Solution {
public:
    string encode(int num) {
        // 1 2 4 6
        if (num == 0) return "";
        int start = 1;
        int width = 1;
        while (true) {
            if (start + (1 << width) > num) {
                num = num - start;
                string ans = "";
                do {
                    ans = to_string(num % 2) + ans;
                    num /= 2;
                } while (num);
                if (width > ans.length()) ans = string(width - ans.length(), '0') + ans;
                return ans;
            }
            start += (1 << width);
            ++width;
        }
        return "";
    }
};

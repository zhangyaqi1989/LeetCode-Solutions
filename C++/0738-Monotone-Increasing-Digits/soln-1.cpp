class Solution {
public:
    int monotoneIncreasingDigits(int num) {
        string num_str = to_string(num);
        string ans;
        const int kN = num_str.length();
        for(int i = 0; i < kN; ++i) {
            string tail = string(kN - i, num_str[i]);
            if (tail <= num_str.substr(i)) {
                ans += num_str[i];
            } else {
                if (num_str[i] != '1') ans += static_cast<char> (num_str[i] - 1);
                ans += string(kN - 1 - i, '9');
                return stoi(ans);
            }
        }
        return stoi(ans);
    }
};

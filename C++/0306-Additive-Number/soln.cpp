class Solution {
public:
    bool isAdditiveNumber(string num) {
        const int kN = num.length();
        for(int i = 1; i < kN; ++i) {
            if(num[0] == '0' && i > 1) break;
            for(int j = i + 1; j <= min(kN - 1, i + 15); ++j) {
                if(num[i] == '0' && j > i + 1) break;
                long long a = stoll(num.substr(0, i));
                long long b = stoll(num.substr(i, j - i));
                int idx = j;
                while(idx < kN) {
                    long long c = a + b;
                    string c_str = to_string(c);
                    if(num.compare(idx, c_str.length(), c_str) != 0) break;
                    idx += c_str.length();
                    a = b;
                    b = c;
                }
                if(idx == kN) return true;
            }
        }
        return false;
    }
};

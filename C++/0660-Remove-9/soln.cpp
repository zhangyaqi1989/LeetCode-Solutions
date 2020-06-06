class Solution {
public:
    int newInteger(int n) {
        // 1 2 3 ...
        vector<int> digits;
        while (n) {
            digits.push_back(n % 9);
            n /= 9;
        }
        int num = 0;
        for(auto it = digits.crbegin(); it != digits.crend(); ++it) {
            num = num * 10 + (*it);
        }
        return num;
    }
};

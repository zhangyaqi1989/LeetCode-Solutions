class Solution {
public:
    string fractionToDecimal(int a, int b) {
        int sign = ((a > 0 && b < 0) || (a < 0 && b > 0)) ? -1 : 1;
        long numerator = labs(a);
        long denominator = labs(b);
        if (numerator % denominator == 0) return sign == 1 ? to_string(numerator / denominator) : "-" + to_string(numerator / denominator);
        long r = numerator % denominator;
        string ans = to_string(numerator / denominator) + ".";
        map<long, int> memo;
        while (r != 0) {
            if(memo.find(r) != memo.end()) {
                ans.insert(memo[r], "(");
                ans += ")";
                break;
            }
            // cout << r << endl;
            memo[r] = ans.length();
            long val = (r * 10) / denominator;
            r = (r * 10) % denominator;
            ans += to_string(val);
        }
        return sign == 1 ? ans : "-" + ans;
    }
};

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        // a / b
        int sign = (long) numerator * denominator < 0 ? -1 : 1;
        long a = abs((long) numerator);
        long b = abs((long) denominator);
        long q = a / b;
        long r = a % b;
        string ans = to_string(q);
        if (sign == -1) ans = '-' + ans;
        unordered_map<long, int> seen;
        if (r != 0) {
            ans += '.';
            while (r != 0) {
                if (seen.find(r) != seen.end()) {
                    ans.insert(seen[r], string("("));
                    return ans += ")";
                }
                seen[r] = ans.size();
                r *= 10;
                long val = r / b;
                long nr = r % b;
                ans += to_string(val);
                r = nr;
            }

        }
        return ans;
    }
};

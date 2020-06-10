class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> digits;
        while(n) {
            digits.push_back(n % 10);
            n /= 10;
        }
        reverse(digits.begin(), digits.end());
        int m = digits.size();
        bool is_decreasing = true;
        for(int i = 1; i < m; ++i) {
            if(digits[i] > digits[i - 1]) {
                is_decreasing = false;
                break;
            }
        }
        if(is_decreasing) return -1;
        next_permutation(digits.begin(), digits.end());
        long long ans = 0;
        for(int d : digits) {
            ans = ans * 10 + d;
        }
        return ans > INT_MAX ? -1 : ans;
    }
};

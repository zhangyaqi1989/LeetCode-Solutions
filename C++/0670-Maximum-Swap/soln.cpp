class Solution {
public:
    int maximumSwap(int num) {
        vector<int> digits;
        do {
            digits.push_back(num % 10);
            num /= 10;
        } while (num);
        reverse(digits.begin(), digits.end());
        const int kN = digits.size();
        for(int i = 0; i < kN; ++i) {
            int cand_idx = -1;
            int cand = digits[i];
            for(int j = kN - 1; j > i; --j) {
                if (digits[j] > cand) {
                    cand = digits[j];
                    cand_idx = j;
                }
            }
            if (cand > digits[i]) {
                swap(digits[i], digits[cand_idx]);
                break;
            }
        }
        int ans = 0;
        for(int d : digits) {
            ans = ans * 10 + d;
        }
        return ans;
    }
};

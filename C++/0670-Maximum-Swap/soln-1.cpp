class Solution {
public:
    int maximumSwap(int num) {
        vector<int> digits;
        do {
            digits.push_back(num % 10);
            num /= 10;
        } while (num);
        const int kN = digits.size();
        for(int i = kN - 1; i >= 0; --i) {
            int cand_idx = -1;
            int cand = digits[i];
            for(int j = 0; j < i; ++j) {
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
        for(auto it = digits.rbegin(); it != digits.rend(); ++it) {
            ans = ans * 10 + *it;
        }
        return ans;
    }
};

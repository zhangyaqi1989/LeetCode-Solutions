class Solution {
public:
    string minInteger(string num, int k) {
        const int kN = num.length();
        for(int i = 0; i < kN; ++i) {
            char mn = num[i];
            int mn_idx = i;
            for(int j = i + 1; j < min(kN, i + k + 1); ++j) {
                if(num[j] < mn) {
                    mn = num[j];
                    mn_idx = j;
                }
            }
            if(mn_idx != i) {
                for(int j = mn_idx; j > i; --j) {
                    char temp = num[j];
                    num[j] = num[j - 1];
                    num[j - 1] = temp;
                }
                k -= (mn_idx - i);
                if (k == 0) break;
            }
        }
        return num;
    }
};

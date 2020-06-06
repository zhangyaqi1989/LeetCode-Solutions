class Solution {
public:
    int findComplement(int num) {
        vector<int> bits;
        while (num) {
            bits.push_back(1 - num % 2);
            num /= 2;
        }
        if (bits.empty()) return 1;
        else {
            int ans = 0;
            int n = bits.size();
            for(int i = n - 1; i >= 0; --i) {
                ans = ans * 2 + bits[i];
            }
            return ans;
        }
    }
};

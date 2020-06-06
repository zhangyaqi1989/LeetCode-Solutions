class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        int i = 0;
        while (n) {
            ans = ans * 2 + (n % 2);
            n >>= 1;
            i += 1;
        }
        return ans << (32 - i);
    }
};
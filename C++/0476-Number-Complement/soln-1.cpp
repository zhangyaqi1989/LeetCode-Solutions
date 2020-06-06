class Solution {
public:
    int findComplement(int num) {
        int ans = 0, idx = 0;
        do {
            if(num % 2 == 0) ans |= (1 << idx);
            ++idx;
            num /= 2;
        } while(num);
        return ans;
    }
};

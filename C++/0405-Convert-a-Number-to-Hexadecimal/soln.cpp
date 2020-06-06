class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        string alphas = "0123456789abcdef";
        string ans = "";
        int cnt = 0;
        while (num && cnt++ < 8) {
            ans = alphas[num & 0xf] + ans;
            num >>= 4;
        }
        return ans;
    }
};

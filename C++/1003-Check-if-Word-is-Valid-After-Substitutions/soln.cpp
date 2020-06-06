class Solution {
public:
    bool isValid(string S) {
        int n = S.length();
        if (n % 3 != 0) return false;
        int As = 0, Bs = 0;
        for(char ch : S) {
            if (ch == 'c') {
                if (!(As > 0 && Bs > 0)) return false;
                else {
                    --As;
                    --Bs;
                }
            } else if (ch == 'a') ++As;
            else ++Bs;
            if (Bs > As) return false;
        }
        return As == 0 && Bs == 0;
    }
};

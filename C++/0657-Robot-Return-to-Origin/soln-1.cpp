class Solution {
public:
    bool judgeCircle(string moves) {
        int LR = 0, UD = 0;
        for(char ch : moves) {
            if (ch == 'L') ++LR;
            else if (ch == 'R') --LR;
            else if (ch == 'U') ++UD;
            else --UD;
        }
        return LR == 0 && UD == 0;
    }
};

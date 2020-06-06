class Solution {
public:
    bool judgeCircle(string moves) {
        int LR = 0, UD = 0;
        for(char ch : moves) {
            switch(ch) {
                case 'L': ++LR; break;
                case 'R': --LR; break;
                case 'U': ++UD; break;
                case 'D': --UD; break;
            }
        }
        return LR == 0 && UD == 0;
    }
};

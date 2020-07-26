class Solution {
public:
    int minFlips(string target) {
        int nflips = 0;
        for(char ch : target) {
            if((ch == '1' && nflips % 2 == 0) || (ch == '0' && nflips % 2 == 1)) {
                ++nflips;
            }
        }
        return nflips;
    }
};

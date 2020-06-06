class Solution {
public:
    bool canWinNim(int n) {
        // the one who removes the last stone will be the winner
        return n % 4 != 0;
    }
};

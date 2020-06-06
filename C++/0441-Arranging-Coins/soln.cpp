class Solution {
public:
    int arrangeCoins(int n) {
        // (1 + x) * x = 2 * n
        // x * x + x - 2 * n
        // (-1 + sqrt(1 + 8 * n)) / 2
        int x = (-1 + (int) sqrt(1 + (double)8 * n)) / 2;
        return x;
    }
};

class Solution {
public:
    bool judgeSquareSum(int c) {
        int i = 0;
        int bound = sqrt(c);
        while (i <= bound) {
            int root = sqrt(c - i * i);
            if (root * root + i * i == c) return true;
            ++i;
        }
        return false;
    }
};

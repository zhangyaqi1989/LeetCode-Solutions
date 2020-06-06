class Solution {
public:
    bool isPerfectSquare(int num) {
        long i = 1L;
        while (i * i < num) ++i;
        return i * i == num;
    }
};

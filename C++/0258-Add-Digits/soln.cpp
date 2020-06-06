class Solution {
public:
    int addDigits(int num) {
        // 1 : 1
        // 10: 1
        // 11: 2
        // 13: 4
        // 9: 9
        return (num - 1) % 9 + 1;
    }
};
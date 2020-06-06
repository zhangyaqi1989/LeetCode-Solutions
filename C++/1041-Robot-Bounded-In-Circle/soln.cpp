class Solution {
public:
    bool isRobotBounded(string instructions) {
        complex<int> d(0, 1), p(0, 0), L(0, 1), R(0, -1);
        for(char ch : instructions) {
            if (ch == 'L') d *= L;
            else if (ch == 'R') d *= R;
            else p += d;
        }
        if (d == complex<int>(0, 1) && (real(p) != 0 || imag(p) != 0)) return false;
        return true;
    }
};

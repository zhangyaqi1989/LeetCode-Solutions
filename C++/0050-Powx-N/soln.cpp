class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n < 0) return 1/x * 1 / myPow(x, -(n + 1));
        double half = myPow(x, n / 2);
        if (n % 2 == 1) return half * half * x;
        else return half * half;
    }
};

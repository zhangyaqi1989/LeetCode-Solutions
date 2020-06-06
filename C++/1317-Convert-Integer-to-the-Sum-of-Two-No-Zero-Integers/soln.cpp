class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        while (true) {
            int a = rand() % n;
            int b = n - a;
            if (IsNoZeroInteger(a) && IsNoZeroInteger(b)) return {a, b};
        }
        return {};
    }
    
private:
    bool IsNoZeroInteger(int n) {
        if (n <= 0) return false;
        do {
            if (n % 10 == 0) return false;
            n /= 10;
        } while (n);
        return true;
    }
};

class Solution {
public:
    bool isHappy(int n) {
        int slow = n, fast = n;
        do {
            slow = func(slow);
            fast = func(func(fast));
        } while (slow != fast);
        if (slow == 1) return true;
        else return false;
    }
    
    int func(int n) {
        int ans = 0;
        while (n != 0) {
            ans += (n % 10) * (n % 10);
            n /= 10;
        }
        return ans;
    }
};

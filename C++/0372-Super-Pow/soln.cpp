class Solution {
public:
    int superPow(int a, vector<int>& b) {
        if (b.empty()) return 1;
        int last_d = b.back();
        b.pop_back();
        return helper(superPow(a, b), 10) * helper(a, last_d) % base;
    }
    
private:
    const int base = 1337;
    int helper(int a, int b) {
        a %= base;
        int ans = 1;
        for(int i = 0; i < b; ++i) ans = (ans * a) % base;
        return ans;
    }
};

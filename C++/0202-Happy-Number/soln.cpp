class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> m;
        while(true)
        {
            int ans = 0;
            while (n)
            {
                int val = n % 10;
                n /= 10;
                ans += val * val;
            }
            if (ans == 1) return true;
            if(m.count(ans)) return false;
            m.insert(ans);
            n = ans;
            
        }
    }
};
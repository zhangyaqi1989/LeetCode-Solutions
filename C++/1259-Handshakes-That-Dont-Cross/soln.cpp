typedef long long ll;
const ll kMod = 1000000007LL;
class Solution {
public:
    int numberOfWays(int num_people) {
        // convert it to a smaller problem
        vector<ll> memo(num_people + 1, 0);
        return static_cast<int>(helper(num_people, &memo));
    }
    
private:    
    ll helper(int n, vector<ll> * memo) {
        if (n == 0 || n == 2) return 1;
        if((*memo)[n] != 0) return (*memo)[n];
        ll ans = 0;
        for(int i = 2; i <= n; i += 2) {
            ans = (ans + helper(i - 2, memo) * helper(n - i, memo) % kMod) % kMod;
        }
        (*memo)[n] = ans;
        return ans;
    }
};

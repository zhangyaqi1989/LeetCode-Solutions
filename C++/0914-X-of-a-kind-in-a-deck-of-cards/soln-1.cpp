class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> counter;
        for(int card : deck) ++counter[card];
        int ans = 0;
        for(auto & p : counter) ans = __gcd(ans, p.second);
        return ans > 1;
    }
};

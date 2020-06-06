class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> m;
        for (int item : deck) 
            m[item] += 1;
        int ans = 0;
        for (auto it : m) {
            ans = __gcd(it.second, ans);
        }
        return ans > 1;
    }
};

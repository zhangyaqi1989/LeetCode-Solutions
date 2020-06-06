class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        if (n % 2) ans.push_back(0);
        n /= 2;
        for(int j = 1; j <= n; ++j) {
            ans.push_back(j);
            ans.push_back(-j);
        }
        return ans;
    }
};

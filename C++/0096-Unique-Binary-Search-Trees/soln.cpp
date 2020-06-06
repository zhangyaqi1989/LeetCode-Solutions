class Solution {
public:
    int numTrees(int n) {
        vector<int> f = {1};
        for(int i = 1; i <= n; ++i)
        {
            int t = 0;
            for(int j = 0; j < i; ++j)
            {
                t += f[j] * f[i - 1 - j];
            }
            f.push_back(t);
        }
        return f.back();
    }
};
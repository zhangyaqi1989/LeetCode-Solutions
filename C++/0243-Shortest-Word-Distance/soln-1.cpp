class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        map<string, vector<int>> m;
        int n = words.size();
        for(int i = 0; i < n; ++i) {
            m[words[i]].push_back(i);
        }
        int ans = n;
        for(auto i1 : m[word1])
            for(auto i2 : m[word2]) {
                if (i1 != i2) ans = min(ans, abs(i1 - i2));
            }
        return ans;
    }
};

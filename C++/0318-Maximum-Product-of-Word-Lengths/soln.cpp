// there is an alternative soln
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> masks(n, 0);
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            for(char ch : words[i]) {
                masks[i] |= (1 << (ch - 'a'));
            }
            for(int j = 0; j < i; ++j) {
                if (!(masks[j] & masks[i]))
                    ans = max(ans, (int) (words[i].size() * words[j].size()));
            }
        }
        return ans;
    }
};

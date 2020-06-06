class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans = {1};
        while (ans.size() < n) {
            int nxt = ans.back() * 10;
            while (nxt > n) {
                nxt /= 10;
                ++nxt;
                while (nxt % 10 == 0) {
                    nxt /= 10;
                }
            }
            ans.push_back(nxt);
        }
        return ans;
    }
};

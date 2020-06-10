class Solution {
public:
    int totalFruit(vector<int>& tree) {
        map<int, int> counter;
        int lo = 0, n = tree.size(), ans = 0;
        for(int i = 0; i < n; ++i) {
            ++counter[tree[i]];
            while (counter.size() > 2) {
                auto it = counter.find(tree[lo]);
                if (--(it->second) == 0) counter.erase(it);
                ++lo;
            }
            ans = max(ans, i - lo + 1);
            cout << ans << endl;
        }
        return ans;
    }
};

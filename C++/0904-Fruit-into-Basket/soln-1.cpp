class Solution {
public:
    int totalFruit(vector<int>& tree) {
        unordered_map<int, int> basket;
        int lo = 0, best = 0;
        const int kN = tree.size();
        for(int i = 0; i < kN; ++i) {
            ++basket[tree[i]];
            while (basket.size() > 2) {
                if(--basket[tree[lo]] == 0) {
                    basket.erase(tree[lo]);
                }
                ++lo;
            }
            best = max(best, i - lo + 1);
        }
        return best;
    }
};

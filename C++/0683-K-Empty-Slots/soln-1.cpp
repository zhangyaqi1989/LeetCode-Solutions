class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int K) {
        set<int> ons;
        const int n = bulbs.size();
        ++K;
        for(int i = 0; i < n; ++i) {
            int pos = bulbs[i];
            auto it = ons.lower_bound(pos);
            if (it != ons.begin() && pos - *prev(it) == K) return i + 1;
            if (it != ons.end() && *(it) - pos == K) return i + 1;
            ons.insert(pos);
        }
        return -1;
    }
};

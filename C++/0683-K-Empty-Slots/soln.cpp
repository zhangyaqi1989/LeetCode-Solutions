class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int K) {
        set<int> bloom;
        int n = bulbs.size();
        for(int day = 1; day <= n; ++day) {
            int flower = bulbs[day - 1];
            auto it = bloom.lower_bound(flower);
            if (it != bloom.begin() && flower - *(prev(it)) == K + 1) return day;
            if (bloom.size() > 0 && *it - flower == K + 1) return day;
            bloom.insert(flower);
        }
        return -1;
    }
};

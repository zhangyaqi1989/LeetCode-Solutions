class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        const int kN = stones.size();
        int n1 = kN / 2, n2 = kN - n1;
        int total1 = (1 << n1);
        set<int> bag1, bag2;
        for(int i = 0; i < total1; ++i) {
            int num = 0;
            for(int j = 0; j < n1; ++j) {
                if (i & (1 << j)) {
                    num += stones[j];
                } else {
                    num -= stones[j];
                }
            }
            bag1.insert(num);
        }
        int total2 = (1 << n2);
        for(int i = 0; i < total2; ++i) {
            int num = 0;
            for(int j = 0; j < n2; ++j) {
                if (i & (1 << j)) {
                    num += stones[n1 + j];
                } else {
                    num -= stones[n1 + j];
                }
            }
            bag2.insert(num);
        }
        // mlog(n), nlog(m)
        int mx = *max_element(stones.begin(), stones.end());
        for(int num : bag1) {
            auto it = bag2.lower_bound(num);
            if (it != bag2.end()) {
                mx = min(mx, *it - num);
            }
            if (it != bag2.begin()) {
                mx = min(mx, num - *prev(it));
            }
        }
        return mx;
    }
};

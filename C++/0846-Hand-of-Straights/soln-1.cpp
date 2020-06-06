class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        int n = hand.size();
        if (n % W != 0) return false;
        map<int, int> counter;
        for(int num : hand) ++counter[num];
        for(int i = 0; i < n / W; ++i) {
            if (counter.empty()) return false;
            int start = counter.begin()->first;
            if (--counter[start] == 0) counter.erase(counter.begin());
            for(int j = 1; j < W; ++j) {
                if (counter.find(++start) == counter.end()) return false;
                if (--counter[start] == 0) counter.erase(start);
            }
        }
        return true;
    }
};

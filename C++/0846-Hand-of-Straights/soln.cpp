class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        int n = hand.size();
        if (n % W != 0) return false;
        map<int, int> counter;
        for(int card : hand) ++counter[card];
        int m = n / W;
        for(int i = 0; i < m; ++i) {
            int start = (*counter.begin()).first;
            // cout << start << endl;
            for(int num = start; num < start + W; ++num) {
                if (counter[num] == 0) return false;
                if (--counter[num] == 0) counter.erase(num);
            }
        }
        return true;
        
    }
};

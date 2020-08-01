class Solution {
public:
    int minSwaps(vector<int>& data) {
        int k = count(data.begin(), data.end(), 1);
        int ones = 0;
        int best = k;
        for(size_t i = 0; i < data.size(); ++i) {
            ones += data[i] == 1;
            if(i >= k) ones -= data[i - k] == 1;
            if(i >= k - 1) best = min(best, k - ones);
        }
        return best;
    }
};

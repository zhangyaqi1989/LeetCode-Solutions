class Solution {
public:
    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>> pairs;
        for(int num = lo; num <= hi; ++num) {
            int cnt = 0;
            int val = num;
            while(val != 1) {
                ++cnt;
                if(val % 2 == 0) val /= 2;
                else val = 3 * val + 1;
            }
            pairs.emplace_back(cnt, num);
        }
        nth_element(pairs.begin(), pairs.begin() + k - 1, pairs.end());
        return (*next(pairs.begin(), k - 1)).second;
    }
};

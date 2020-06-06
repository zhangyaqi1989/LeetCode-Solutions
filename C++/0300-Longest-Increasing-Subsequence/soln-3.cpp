class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        multiset<int> tails;
        for(int num : nums) {
            tails.insert(num);
            auto it = tails.find(num);
            if (next(it) != tails.end()) {
                tails.erase(next(it));
            }
        }
        return tails.size();
    }
};

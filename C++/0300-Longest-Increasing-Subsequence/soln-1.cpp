class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;
        for(int num : nums) {
            auto it = lower_bound(tails.begin(), tails.end(), num);
            if (it == tails.end()) tails.push_back(num);
            else *it = num;
        }
        return tails.size();
    }
};

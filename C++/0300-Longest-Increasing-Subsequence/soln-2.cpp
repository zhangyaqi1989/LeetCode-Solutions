class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;
        for(int num : nums) {
            int idx = lower_bound(tails.begin(), tails.end(), num) - tails.begin();
            if (idx < tails.size()) tails[idx] = num;
            else tails.push_back(num);
        }
        return tails.size();
    }
};

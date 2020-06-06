class Solution {
public:
    int sort_and_count(vector<int>::iterator begin, vector<int>::iterator end) {
        if (end - begin <= 1) return 0;
        auto mid = begin + (end - begin) / 2;
        int count = sort_and_count(begin, mid) + sort_and_count(mid, end);
        for(auto i = begin, j = mid; i != mid; ++i) {
            while (j != end && *i > 2L * *j)
                ++j;
            count += j - mid;
        }
        inplace_merge(begin, mid, end);
        return count;
    }
    
    int reversePairs(vector<int>& nums) {
        return sort_and_count(nums.begin(), nums.end());
    }
};
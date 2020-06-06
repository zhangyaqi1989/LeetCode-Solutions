class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return countAndSort(nums.begin(), nums.end());
    }
    
    int countAndSort(vector<int>::iterator begin, vector<int>::iterator end) {
        if (end - begin <= 1) return 0;
        auto mid = begin + (end - begin) / 2;
        int cnt = countAndSort(begin, mid) + countAndSort(mid, end);
        for(auto i = begin, j = mid; i != mid; ++i) {
            while (j != end and (*i) / 2.0 > (*j)) ++j;
            cnt += j - mid;
        }
        inplace_merge(begin, mid, end);
        return cnt;
    }  
};


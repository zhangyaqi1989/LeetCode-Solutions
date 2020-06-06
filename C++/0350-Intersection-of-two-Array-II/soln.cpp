class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        for(auto num : nums1) m[num] ++;
        vector<int> ans;
        for(auto num: nums2)
            if (m[num]-- > 0)
                ans.push_back(num);
        return ans;
    }
};
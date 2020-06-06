class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> seen(nums1.begin(), nums1.end());
        vector<int> ans;
        for(int num : nums2) {
            if (seen.count(num)) {
                seen.erase(num);
                ans.push_back(num);
            }
        }
        return ans;
    }
};

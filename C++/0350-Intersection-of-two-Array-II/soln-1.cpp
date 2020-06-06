class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) swap(nums1, nums2);
        multiset<int> seen;
        for(int num : nums1) seen.insert(num);
        vector<int> ans;
        for(int num : nums2) {
            // cout << num << endl;
            auto it = seen.find(num);
            if (it != seen.end()) {
                seen.erase(it);
                ans.push_back(num);
            }
            if (seen.empty()) break;
        }
        return ans;
    }
};

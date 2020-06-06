class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s;
        for(auto num : nums1) s.insert(num);
        vector<int> ans;
        for(auto num : nums2)
        {
            if(s.count(num))
            {
                s.erase(num);
                ans.push_back(num);
            }
        }
        return ans;
    }
};
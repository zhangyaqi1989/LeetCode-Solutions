class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stk;
        unordered_map<int, int> m;
        int n = nums2.size();
        for(int i = 0; i < n; ++i) {
            int num = nums2[i];
            while (!stk.empty() && num > stk.top()) {
                m[stk.top()] = num;
                stk.pop();
            }
            stk.push(num);
        }
        vector<int> ans;
        for(int num : nums1) {
            auto it = m.find(num);
            if (it == m.end()) ans.push_back(-1);
            else ans.push_back(it->second);
        }
        return ans;
        
    }
};

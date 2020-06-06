class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> idxes;
        int n2 = nums2.size();
        for(int i = 0; i < n2; ++i) idxes[nums2[i]] = i;
        vector<int> nxts(n2, -1);
        // how to fill nxts
        stack<int> st;
        for(int i = 0; i < n2; ++i) {
            while(!st.empty() && nums2[i] > nums2[st.top()]) {
                nxts[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        vector<int> ans;
        for(int num : nums1) {
            int j = nxts[idxes[num]];
            if (j == -1) ans.push_back(-1);
            else ans.push_back(nums2[j]);
        }
        return ans;
    }
};

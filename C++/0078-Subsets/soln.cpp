class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs(1, vector<int>());
        for(auto num : nums)
        {
            int n = subs.size();
            for(int i = 0; i < n; ++i)
            {
                subs.push_back(subs[i]);
                subs.back().push_back(num);
            }
        }
        return subs;
    }
};
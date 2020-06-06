class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int idx = 1;
        vector<string> ans;
        for(int num : target) {
            while(idx != num) {
                ans.push_back("Push");
                ans.push_back("Pop");
                ++idx;
            }
            ans.push_back("Push");
            ++idx;
        }
        return ans;
    }
};

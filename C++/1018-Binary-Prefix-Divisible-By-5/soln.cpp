class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> ans;
        ans.reserve(A.size());
        int num = 0;
        for(int d : A) {
            num = (num * 2 + d) % 5;
            if (num == 0) {
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }
        return ans;
    }
};

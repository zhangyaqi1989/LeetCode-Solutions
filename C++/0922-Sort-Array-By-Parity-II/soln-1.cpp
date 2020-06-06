class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        vector<int> odds, evens;
        for(int a : A) {
            if (a % 2 == 1) odds.push_back(a);
            else evens.push_back(a);
        }
        vector<int> ans;
        int oi = 0, ei = 0;
        for(int i = 0; i < A.size(); ++i) {
            if (i % 2 == 1) ans.push_back(odds[oi++]);
            else ans.push_back(evens[ei++]);
        }
        return ans;
    }
};

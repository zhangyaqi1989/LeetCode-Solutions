class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> numstrs;
        for(int num : nums) {
            numstrs.push_back(to_string(num));
        }
        sort(numstrs.begin(), numstrs.end(), [&](string & a, string & b) {return a + b > b + a;});
        string ans;
        for(string str : numstrs) {
            ans += str;
        }
        int idx = 0;
        for(; idx < ans.length() - 1; ++idx) {
            if (ans[idx] != '0') break;
        }
        return ans.substr(idx);
    }
};

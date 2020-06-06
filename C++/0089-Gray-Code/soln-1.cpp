class Solution {
public:
    vector<int> grayCode(int n) {
        if (n == 0) return {0};
        vector<string> s_lst = {"0", "1"};
        while (n-- > 1) {
            vector<string> temp;
            for(auto s : s_lst) temp.push_back("0" + s);
            for(auto it = s_lst.rbegin(); it != s_lst.rend(); ++it) {
                temp.push_back("1" + (*it));
            }
            swap(temp, s_lst);
        }
        vector<int> ans;
        for(auto s : s_lst) ans.push_back(stoi(s, nullptr, 2));
        return ans;
    }
};

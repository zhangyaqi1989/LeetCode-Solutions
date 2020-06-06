class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> phone = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        if(digits.size() == 0) return ans;
        ans.push_back("");
        for(auto digit : digits)
        {
            int num = digit - '0';
            vector<string> temp;
            for(auto item : ans)
                for(auto ch : phone[num])
                    temp.push_back(item + ch);
            swap(ans, temp);
        }
        return ans;
    }
};
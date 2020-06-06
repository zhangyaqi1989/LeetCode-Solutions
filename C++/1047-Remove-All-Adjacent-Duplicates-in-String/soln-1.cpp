class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stk;
        for(char ch : s) {
            if (!stk.empty() && stk.top() == ch) stk.pop();
            else stk.push(ch);
        }
        string ans = "";
        while (!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
};

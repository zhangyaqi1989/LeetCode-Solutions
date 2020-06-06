class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> stk;
        stk.push("");
        for(char ch : s) {
            if (ch == '(') {
                stk.push("");
            } else if (ch == ')') {
                string t = stk.top();
                stk.pop();
                reverse(t.begin(), t.end());
                stk.top() += t;
            } else {
                stk.top() += ch;
            }
        }
        return stk.top();
    }
};

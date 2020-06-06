class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(char ch : s) {
            if (stk.empty() || ch == '(' || ch == '[' || ch == '{') {
                stk.push(ch);
            } else {
                if ((ch == ')' && stk.top() == '(') || (ch == '}' && stk.top() == '{') || (ch == ']' && stk.top() == '['))
                    stk.pop();
                else
                    return false;
            }
        }
        return stk.empty();
    }
};

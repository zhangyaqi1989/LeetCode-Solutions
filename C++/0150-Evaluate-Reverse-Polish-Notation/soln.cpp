class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(string token : tokens) {
            if (isOp(token)) {
                int rhs = s.top();
                s.pop();
                int lhs = s.top();
                s.pop();
                int ret = func(token, lhs, rhs);
                s.push(ret);
            } else {
                s.push(stoi(token));
            }
        }
        return s.top();
    }
    
    bool isOp(string & token) {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }
    
    int func(string & op, int lhs, int rhs) {
        if (op == "+") return lhs + rhs;
        else if (op == "-") return lhs - rhs;
        else if (op == "*") return lhs * rhs;
        else return lhs / rhs;
    }
};

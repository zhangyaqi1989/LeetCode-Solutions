class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> v_st;
        for(auto & token : tokens) {
            if (is_op(token)) {
                process_op(v_st, token[0]);
            } else {
                v_st.push(stoi(token));
            }
        }
        return v_st.top();
    }
    
private:
    bool is_op(const string & token) {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }
    
    void process_op(stack<int> & v_st, char op) {
        int r = v_st.top(); v_st.pop();
        int l = v_st.top(); v_st.pop();
        switch (op) {
            case '+': v_st.push(l + r); break;
            case '-': v_st.push(l - r); break;
            case '*': v_st.push(l * r); break;
            case '/': v_st.push(l / r); break;
        }
    }
};

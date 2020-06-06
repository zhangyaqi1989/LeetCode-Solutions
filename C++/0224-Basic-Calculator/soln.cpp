bool delim(char c) {
    return c == ' ';
}

bool is_op(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int priority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return -1;
}

void process_op(stack<int> & st, char op) {
    int r = st.top(); st.pop();
    int l = st.top(); st.pop();
    switch(op) {
        case '+': st.push(l + r); break;
        case '-': st.push(l - r); break;
        case '*': st.push(l * r); break;
        case '/': st.push(l / r); break;
    }
}

class Solution {
public:
    int calculate(string s) {
        stack<int> v_st;
        stack<char> op_st;
        const int n = s.length();
        for(int i = 0; i < n; ++i) {
            if (delim(s[i])) continue;
            if (s[i] == '(') {
                op_st.push('(');
            } else if (s[i] == ')') {
                while (op_st.top() != '(') {
                    process_op(v_st, op_st.top());
                    op_st.pop();
                }
                op_st.pop();
            } else if (is_op(s[i])) {
                char cur_op = s[i];
                while (!op_st.empty() && priority(op_st.top()) >= priority(cur_op)) {
                    process_op(v_st, op_st.top());
                    op_st.pop();
                }
                op_st.push(cur_op);
            } else {
                int number = 0;
                while (i < n && isdigit(s[i])) {
                    number = number * 10 + (s[i++] - '0');
                    // cout << number << endl;
                }
                --i;
                v_st.push(number);
            }
        }
        while(!op_st.empty()) {
            process_op(v_st, op_st.top());
            op_st.pop();
        }
        return v_st.top();
    }
};

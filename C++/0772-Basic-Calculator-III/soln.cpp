bool delim(char ch) {return ch == ' ';}

bool is_op(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int priority(char op) {
    if (op < 0) return 3;
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return -1;
}

bool is_unary(char op) {
    return op == '+' || op == '-';
} 

void process_op(stack<long> & v_st, char op) {
    if (op < 0) {
        op = -op;
        long v = v_st.top();
        v_st.pop();
        if (op == '+') v_st.push(v);
        else if (op == '-') v_st.push(-v);
    } else {
        long r = v_st.top(); v_st.pop();
        long l = v_st.top(); v_st.pop();
        // cout << l << op << r << endl;
        switch(op) {
            case '+': v_st.push(l + r); break;
            case '-': v_st.push(l - r); break;
            case '*': v_st.push(l * r); break;
            case '/': v_st.push(l / r); break;
        }
    }
}

class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        bool maybe_unary = true;
        stack<long> v_st;
        stack<char> op_st;
        for(int i = 0; i < n; ++i) {
            if (delim(s[i])) continue;
            if (s[i] == '(') {
                op_st.push('(');
                maybe_unary = true;
            } else if (s[i] == ')') {
                while (op_st.top() != '(') {
                    process_op(v_st, op_st.top());
                    op_st.pop();
                }
                op_st.pop(); // pop the '('
                maybe_unary = false;
            } else if (is_op(s[i])) {
                char cur_op = s[i];
                if(maybe_unary && is_unary(cur_op)) cur_op = -cur_op;
                while (!op_st.empty() && ((cur_op >= 0 && priority(op_st.top()) >= priority(cur_op)) || (cur_op < 0 && priority(op_st.top()) > priority(cur_op)))) {
                    process_op(v_st, op_st.top());
                    op_st.pop();
                }
                op_st.push(cur_op);
                maybe_unary = true;
            } else {
                long num = 0;
                while (i < n && isdigit(s[i]))
                    num = num * 10 + (s[i++] - '0');
                v_st.push(num);
                --i;
                maybe_unary = false;
            }
        }
        
        while(!op_st.empty()) {
            process_op(v_st, op_st.top());
            op_st.pop();
        }
        return (int) v_st.top();
    } // end func
};

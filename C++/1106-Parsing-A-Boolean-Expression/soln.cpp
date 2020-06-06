class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> v_st;
        stack<char> op_st;
        for(char ch : expression) {
            if (ch == ',') continue;
            if (ch == '|' || ch == '&' || ch == '!') {
                op_st.push(ch);
            } else if (ch == '(') {
                v_st.push(ch);
            } else if (ch == ')') {
                vector<char> oprands;
                while (v_st.top() != '(') {
                    oprands.push_back(v_st.top());
                    v_st.pop();
                }
                v_st.pop();
                char op = op_st.top();
                op_st.pop();
                char v;
                if (op == '&') {
                    v = all_of(oprands.begin(), oprands.end(), [](char a) {return a == 't';}) ? 't' : 'f';
                } else if (op == '|') {
                    v = any_of(oprands.begin(), oprands.end(), [](char a) {return a == 't';}) ? 't' : 'f';
                } else {
                    v = oprands[0] == 't' ? 'f' : 't';
                }
                v_st.push(v);
            } else {
                v_st.push(ch);
            }
        }
        return v_st.top() == 't' ? true : false;
    }
};

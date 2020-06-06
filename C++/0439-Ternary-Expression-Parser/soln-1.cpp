class Solution {
public:
    string parseTernary(string expression) {
        stack<string> v_st;
        const int kN = expression.length();
        string val;
        for(int i = kN - 1; i >= 0; --i){
            char ch = expression[i];
            if (ch == '?') {
                if(!val.empty()) {
                    v_st.push(val);
                    val.clear();
                }
                string l = v_st.top();
                v_st.pop();
                string r = v_st.top();
                v_st.pop();
                if (expression[i - 1] == 'T') {
                    v_st.push(l);
                } else {
                    v_st.push(r);
                }
                --i;
            } else if (ch == ':') {
                if (!val.empty()) {
                    v_st.push(val);
                    val.clear();
                }
            } else {
                val += ch;
            }
        }
        return v_st.top();
    }
};

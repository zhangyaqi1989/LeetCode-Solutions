class Solution {
public:
    string decodeString(string s) {
        stack<int> num_st;
        stack<string> str_st;
        str_st.push("");
        const int n = s.length();
        for(int i = 0; i < n; ++i) {
            if (s[i] == '[') {
                str_st.push("");
            } else if (s[i] == ']') {
                string str = str_st.top();
                str_st.pop();
                int cnt = num_st.top();
                num_st.pop();
                for(int j = 0; j < cnt; ++j) 
                    str_st.top() += str;
            } else if (isdigit(s[i])) {
                int num = 0;
                while(i < n && isdigit(s[i])) {
                    num = num * 10 + (s[i++] - '0');
                }
                --i;
                num_st.push(num);
            } else {
                while(i < n && isalpha(s[i])) {
                    str_st.top() += s[i++];
                }
                --i;
            }
        }
        return str_st.top();

    }
};

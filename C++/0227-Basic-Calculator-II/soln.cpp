class Solution {
public:
    int calculate(string s) {
        int cur = 0, last = 0;
        char op = '+';
        const int n = s.length();
        for(int i = 0; i < n; ++i) {
            if(s[i] == ' ') continue;
            else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                op = s[i];
            } else {
                int num = 0;
                while(i < n && isdigit(s[i])) num = num * 10 + (s[i++] - '0');
                --i;
                if (op == '/' or op == '*') {
                    cur -= last;
                    if (op == '*') {
                        cur += last * num;
                        last = last * num;
                    } else {
                        cur += last / num;
                        last = last / num;
                    }
                } else {
                    if (op == '+') {
                        cur += num;
                        last = num;
                    } else {
                        cur -= num;
                        last = -num;
                    }
                }
            }
        }
        return cur;
    }
};

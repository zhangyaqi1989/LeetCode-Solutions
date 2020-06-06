class Solution {
public:
    int compress(vector<char>& chars) {
        char cur = chars[0];
        int cnt = 0, idx = 0, n = chars.size();
        for(char ch : chars) {
            if (cur == ch) {
                ++cnt;
            } else {
                write(chars, cur, cnt, idx);
                cnt = 1;
                cur = ch;
            }
        }
        write(chars, cur, cnt, idx);
        return idx;
    }
    
    void write(vector<char>& chars, char cur, int cnt, int & idx) {
        chars[idx++] = cur;
        if(cnt > 1) {
            string temp = to_string(cnt);
            for(char c : temp)
                chars[idx++] = c;
        }        
    }
};

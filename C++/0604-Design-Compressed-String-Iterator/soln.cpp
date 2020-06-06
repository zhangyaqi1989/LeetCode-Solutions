class StringIterator {
    char ch;
    int cnt;
    int idx;
    string str;
public:
    StringIterator(string compressedString) {
        ch = ' ';
        cnt = 0;
        idx = 0;
        str = compressedString;
    }
    
    char next() {
        _update();
        if (cnt > 0) {
            --cnt;
            return ch;
        } else {
            return ' ';
        }
    }
    
    void _update() {
        int n = str.size();
        while (idx < n && cnt == 0) {
            ch = str[idx++];
            int num = 0;
            while (idx < n && isdigit(str[idx]))
                num = num * 10 + (str[idx++] - '0');
            cnt = num;
        }        
    }
    
    bool hasNext() {
        _update();
        return cnt > 0;
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator obj = new StringIterator(compressedString);
 * char param_1 = obj.next();
 * bool param_2 = obj.hasNext();
 */

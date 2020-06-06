// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        char * temp = new char[4];
        int idx = 0;
        bool done = false;
        while (n > 0 && !done) {
            int m = read4(temp);
            if (m < 4) done = true;
            for(int j = 0; n > 0 && j < m; ++j, --n) buf[idx++] = temp[j];
        }
        return idx;
    }
};

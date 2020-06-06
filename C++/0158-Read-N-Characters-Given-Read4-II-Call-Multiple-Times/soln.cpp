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
        int cnt = 0;
        while (cnt < n) {
            if (idx_ == buf_size_) {
                buf_size_ = read4(buf_);
                idx_ = 0;
            }
            int avil = buf_size_ - idx_;
            if (avil == 0) break;
            for(int i = 0; i < min(avil, n - cnt); ++i) {
                buf[cnt++] = buf_[idx_++];
            }
        }
        return cnt;
    }
    
private:
    char buf_[4];
    int idx_ = 0;
    int buf_size_ = 0;
};

/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char[] buf);
 */
public class Solution extends Reader4 {
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    public int read(char[] buf, int n) {
        char [] temp = new char[4];
        int idx = 0;
        boolean done = false;
        while (n > 0 && !done) {
            int m = read4(temp);
            if (m < 4) done = true;
            for(int j = 0; j < m && n > 0; --n, ++j) {
                buf[idx++] = temp[j];
            }
        }
        return idx;
    }
}

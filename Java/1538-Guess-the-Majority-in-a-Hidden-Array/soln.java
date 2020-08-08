/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface ArrayReader {
 *   public:
 *     // Compares 4 different elements in the array
 *     // return 4 if the values of the 4 elements are the same (0 or 1).
 *     // return 2 if three elements have a value equal to 0 and one element has value equal to 1 or vice versa.
 *     // return 0 : if two element have a value equal to 0 and two elements have a value equal to 1.
 *     public int query(int a, int b, int c, int d);
 *
 *     // Returns the length of the array
 *     public int length();
 * };
 */

class Solution {
    public int guessMajority(ArrayReader reader) {
        final int kN = reader.length();
        int a_cnt = 1, b_cnt = 0;
        int a = reader.query(0, 1, 2, 3);
        int b = reader.query(0, 1, 2, 4);
        int a_idx = 3;
        int b_idx = -1;
        for(int i = 4; i < kN; ++i) {
            if(reader.query(0, 1, 2, i) == a) {
                ++a_cnt;
            } else {
                ++b_cnt;
                b_idx = i;
            }
        }
        
        for(int miss = 0; miss < 3; ++miss) {
            int [] temp = new int[4];
            int idx = 0;
            for(int val = 0; val <= 4; ++val) {
                if(val != miss) temp[idx++] = val;
            }
            if(reader.query(temp[0], temp[1], temp[2], temp[3]) == b) {
                a_cnt += 1;
            } else {
                b_cnt += 1;
                b_idx = miss;
            }
        }
        
        if(a_cnt > b_cnt) return a_idx;
        else if(a_cnt < b_cnt) return b_idx;
        else return -1;        
    }
}

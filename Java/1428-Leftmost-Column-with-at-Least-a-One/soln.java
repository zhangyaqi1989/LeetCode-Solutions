/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface BinaryMatrix {
 *     public int get(int row, int col) {}
 *     public List<Integer> dimensions {}
 * };
 */

class Solution {
    public int leftMostColumnWithOne(BinaryMatrix binaryMatrix) {
        List<Integer> dim = binaryMatrix.dimensions();
        int rows = dim.get(0), cols = dim.get(1);
        int lo = 0, hi = cols - 1;
        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if(Valid(binaryMatrix, mid, rows)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return Valid(binaryMatrix, lo, rows) ? lo : -1;
    }
    
    public boolean Valid(BinaryMatrix mat, int col, int rows) {
        for(int row = 0; row < rows; ++row) {
            if(mat.get(row, col) == 1) return true;
        }
        return false;
    }
}

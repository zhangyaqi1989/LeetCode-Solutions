/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        auto dim = binaryMatrix.dimensions();
        int rows = dim[0], cols = dim[1];
        int lo = 0, hi = cols - 1;
        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if(Valid(binaryMatrix, mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return Valid(binaryMatrix, lo) ? lo : -1;
    }
    
private:
    bool Valid(BinaryMatrix & mat, int col) {
        auto dim = mat.dimensions();
        int rows = dim[0];
        for(int row = 0; row < rows; ++row) {
            if(mat.get(row, col)) return true;
        }
        return false;
    }
};

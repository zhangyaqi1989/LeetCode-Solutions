class Solution {
    public int smallestCommonElement(int[][] mat) {
        int [] counter = new int [10001];
        int m = mat.length;
        for(int [] row : mat) {
            for(int num : row) {
                if (++counter[num] == m) return num;
            }
        }
        return -1;
    }
}

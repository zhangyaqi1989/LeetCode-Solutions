class Solution {
    public boolean validateBinaryTreeNodes(int n, int[] leftChild, int[] rightChild) {
        int cnt = 0;
        for(int l : leftChild) {
            if (l != -1) cnt += 1;
        }
        for(int r : rightChild) {
            if (r != -1) cnt += 1;
        }
        return cnt == n - 1;
    }
}

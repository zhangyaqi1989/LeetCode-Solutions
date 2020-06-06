class Solution {
    public boolean isValidSerialization(String preorder) {
        int cnt = 1;
        String [] tokens = preorder.split(",");
        for(String token : tokens) {
            if (cnt == 0) return false;
            if (token.equals("#")) {
                --cnt;
            } else {
                ++cnt;
            }
        }
        return cnt == 0;
    }
}

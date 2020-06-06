class Solution {
    public boolean isValidSerialization(String preorder) {
        String [] tokens = preorder.split(",");
        int nslots = 1;
        for(String token : tokens) {
            if (token.equals("#")) {
                if (--nslots < 0) return false;
            } else {
                if (nslots <= 0) return false;
                ++nslots;
            }
        }
        return nslots == 0;
    }
}

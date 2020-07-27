class Solution {
    public int minFlips(String target) {
        int nflips = 0;
        for(char ch : target.toCharArray()) {
            if((ch == '1') != (nflips % 2 == 1)) {
                ++nflips;
            }
        }
        return nflips;
    }
}

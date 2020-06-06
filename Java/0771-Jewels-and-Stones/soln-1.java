class Solution {
    public int numJewelsInStones(String J, String S) {
        int[] jewels = new int[256];
        for(char ch : J.toCharArray()) ++jewels[ch];
        int cnt = 0;
        for(char ch : S.toCharArray()) {
            if (jewels[ch] > 0) ++cnt;
        }
        return cnt;
    }
}

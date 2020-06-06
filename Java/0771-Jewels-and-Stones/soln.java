class Solution {
    public int numJewelsInStones(String J, String S) {
        Set<Character> jew = new HashSet<Character>();
        for(char j : J.toCharArray()) jew.add(j);
        int res = 0;
        for(char s: S.toCharArray()) if (jew.contains(s)) ++res;
        return res;
    }
}
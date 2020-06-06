class Solution {
    public boolean checkIfCanBreak(String s1, String s2) {
        char [] chars1 = s1.toCharArray();
        char [] chars2 = s2.toCharArray();
        Arrays.sort(chars1);
        Arrays.sort(chars2);
        return check(chars1, chars2) || check(chars2, chars1);
    }
    
    private boolean check(char [] chars1, char [] chars2) {
        int n = chars1.length;
        for(int i = 0; i < n; ++i) {
            if(chars1[i] < chars2[i]) return false;
        }
        return true;
    }
}

class Solution {
    public boolean detectCapitalUse(String word) {
        int nupper = 0;
        for(char ch : word.toCharArray()) {
            if (Character.isUpperCase(ch)) ++nupper;
        }
        // System.out.println(nupper);
        if (nupper == 1 && Character.isUpperCase(word.charAt(0))) return true;
        return nupper == 0 || nupper == word.length();
    }
}

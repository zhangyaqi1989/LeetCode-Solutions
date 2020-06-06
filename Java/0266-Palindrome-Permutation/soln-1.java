class Solution {
    public boolean canPermutePalindrome(String s) {
        Set<Character> pool = new HashSet<>();
        for(Character ch : s.toCharArray()) {
            if (pool.contains(ch)) {
                pool.remove(ch);
            } else {
                pool.add(ch);
            }
        }
        return pool.size() == 0 || pool.size() == 1;
    }
}

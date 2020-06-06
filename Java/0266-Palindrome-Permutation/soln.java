class Solution {
    public boolean canPermutePalindrome(String s) {
        Map<Character, Integer> counter = new HashMap<>();
        for(char ch : s.toCharArray()) {
            if (counter.get(ch) == null) {
                counter.put(ch, 0);
            }
            counter.put(ch, counter.get(ch) + 1);
        }
        int cnt = 0;
        for(Character ch : counter.keySet()) {
            if(counter.get(ch) % 2 == 1) {
                ++cnt;
                if (cnt > 1) return false;
            }
        }
        return true;
    }
}

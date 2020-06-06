class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map<Character, Integer> map = new HashMap<Character, Integer>();
        int i = 0;
        int res = 0;
        for(int j = 0; j < s.length(); j++)
        {
            if (map.containsKey(s.charAt(j)))
                i = Math.max(i, map.get(s.charAt(j)));
            map.put(s.charAt(j), j + 1);
            res = Math.max(res, j - i + 1);
        }
        return res;
    }
}
class Solution {
    public int[] numSmallerByFrequency(String[] queries, String[] words) {
        int [] fs = new int [words.length];
        for(int i = 0; i < words.length; ++i) fs[i] = func(words[i]);
        Arrays.sort(fs);
        int [] ans = new int [queries.length];
        for(int i = 0; i < queries.length; ++i) {
            int f = func(queries[i]);
            int lo = 0, hi = words.length;
            while(lo < hi) {
                int mid = lo + (hi - lo) / 2;
                if (fs[mid] > f) hi = mid;
                else lo = mid + 1;
            }
            ans[i] = words.length - lo;
        }
        return ans;
    }
    
    private int func(String word) {
        char [] chars = new char[26];
        for(char ch : word.toCharArray()) ++chars[ch - 'a'];
        for(int i = 0; i < 26; ++i) {
            if (chars[i] != 0) return chars[i];
        }
        return 0;
    }
}

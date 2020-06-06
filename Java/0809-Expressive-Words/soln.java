class Solution {
    public int expressiveWords(String S, String[] words) {
        List<int []> gs = encode(S);
        // System.out.println(gs.size());
        int cnt = 0;
        for(String word : words) {
            List<int []> gw = encode(word);
            if (gs.size() != gw.size()) continue;
            boolean valid = true;
            for(int i = 0; i < gs.size(); ++i) {
                // System.out.println(gs.get(i)[1] + " " + gw.get(i)[1]);
                if (gs.get(i)[0] == gw.get(i)[0] && (gs.get(i)[1] == gw.get(i)[1] || (gs.get(i)[1] > gw.get(i)[1] && gs.get(i)[1] >= 3))) continue;
                valid = false;
                break;
            }
            if (valid) ++cnt;
        }
        return cnt;
    }
    
    public List<int []> encode(String S) {
        List<int []> ans = new ArrayList<>();
        int lo = 0, n = S.length();
        for(int i = 0; i < n; ++i) {
            if (S.charAt(i) != S.charAt(lo)) {
                ans.add(new int[] {S.charAt(lo) - 'a', i - lo});
                lo = i;
            }
        }
        ans.add(new int [] {S.charAt(lo) - 'a', n - lo});
        return ans;
    }
}

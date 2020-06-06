class Solution {
    public List<String> simplifiedFractions(int n) {
        List<String> ans = new ArrayList<>();
        Set<String> cands = new HashSet<>();
        for(int a = 2; a <= n; ++a) {
            for(int b = 1; b < a; ++b) {
                int g = gcd(a, b);
                cands.add(Integer.toString(b / g) + "/" + Integer.toString(a / g));
            }
        }
        for(String cand : cands) ans.add(cand);
        return ans;
    }
    
    public int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}
